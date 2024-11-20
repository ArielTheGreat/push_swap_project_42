/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:46:37 by frocha            #+#    #+#             */
/*   Updated: 2024/11/11 18:46:39 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

int	search_in_array(int *integer_list, int size, char *value)
{
    int counter = 0;
    int integer = ft_atoi(value);

    while (counter < size && integer_list[counter] != integer)
        counter++;
    return (counter < size ? counter : -1);
}

int ft_check_not_digit_character(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != '+' && str[i] != '-')
			return (1);
		i++;
	}
	return (0);
}

int	*process_arguments(int argc, char *argv[])
{
	int	*array_int = malloc((argc - 1) * sizeof(int));
	int	counter = 1;
	int	counter_for_array = 0;

	if (!array_int)
		return (NULL);
	while (counter < argc)
	{
		if (ft_check_not_digit_character(argv[counter]) == 1)
		{
			free(array_int);
			return (NULL);
		}

		array_int[counter_for_array] = ft_atoi(argv[counter]);
		counter++;
		counter_for_array++;
	}
	order_array_quicksort(array_int, argc - 1);
	return (array_int);
}

t_list	*create_and_link_nodes(int *array_int, int argc, char **argv)
{
	t_list	*first_node = NULL;
	t_list	*last_node = NULL;
	int		counter = 1;

	while (counter < argc)
	{
		int index = search_in_array(array_int, argc - 1, argv[counter]);
		if (index == -1)
		{
			ft_lstclear(&first_node, free); // Cleanup if search fails
			free(array_int);
			return (NULL);
		}
		t_list *new_node = create_node(index);
		if (!new_node)
		{
			ft_lstclear(&first_node, free);
			return (NULL);
		}
		if (counter == 1)
			first_node = new_node;
		else
			last_node->next = new_node;
		last_node = new_node;
		counter++;
	}
	return (first_node);
}

void print_content(void *content)
{
    printf("%d ", *(int *)content);
}

void	do_things(t_list *first_node_a, int counter)
{
	t_list	*first_node_b = NULL;
	int		is_sorted = check_order_min_to_max(first_node_a);

	if (is_sorted == 1)
	{
		ft_lstclear(&first_node_a, free); // Free the list if already sorted
		return;
	}

	apply_algorithm(&first_node_a, &first_node_b, counter);
	ft_lstiter(first_node_a, print_content);
    printf("\n");
	ft_lstclear(&first_node_a, free);
}

int	main(int argc, char *argv[])
{
	int		*array_int;
	t_list	*first_node;

	if (argc < 2)
		return (0);
	array_int = process_arguments(argc, argv);
	if (!array_int)
	{
		printf("Invalid argument");
		return (1);
	}
	first_node = create_and_link_nodes(array_int, argc, argv);
	if (!first_node)
	{
		free(array_int);
		return (1);
	}
	ft_lstiter(first_node, print_content);
	printf("\n");
	do_things(first_node, argc - 1);
	//free(array_int);
	return (0);
}
