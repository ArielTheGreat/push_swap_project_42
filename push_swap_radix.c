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
	int	counter;
	int	integer;

	counter = 0;
	integer = ft_atoi(value);
	while (counter < size && integer_list[counter] != integer)
		counter++;
	if (counter < size)
		return (counter);
	else
		return (-1);
}

int	ft_check_not_digit_character(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != '+' && str[i] != '-')
			return (1);
		i++;
	}
	return (0);
}

int	*process_arguments(int argc, char *argv[])
{
	int	*array_int;
	int	counter;
	int	counter_for_array;

	array_int = malloc((argc - 1) * sizeof(int));
	if (!array_int)
		return (NULL);
	counter = 1;
	counter_for_array = 0;
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

void	do_things(t_list *first_node_a, int counter)
{
	t_list	*first_node_b;
	int		is_sorted;

	first_node_b = NULL;
	is_sorted = check_order_min_to_max(first_node_a);
	if (is_sorted == 1)
	{
		ft_lstclear(&first_node_a, free);
		return ;
	}
	apply_algorithm(&first_node_a, &first_node_b, counter);
	ft_lstclear(&first_node_a, free);
}
