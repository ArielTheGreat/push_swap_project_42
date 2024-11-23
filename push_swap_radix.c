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

int	search_in_array(int *integer_list, int size, int value)
{
	int	counter;

	counter = 0;
	while (counter < size && integer_list[counter] != value)
		counter++;
	if (counter < size)
		return (counter);
	else
	{
		return (-1);
	}
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

int check_validity(char **elements, int *counter_arguments)
{
	int i;

	i = 0;
	while(elements[i] != NULL)
	{	
		printf("AA:%s", elements[i]);
		if (ft_check_not_digit_character(elements[i]) == 1
			|| ft_check_is_int(elements[i]) == 0)
		{
			return (1);
		}
		*counter_arguments = *counter_arguments + 1;
		i++;
	}
	return (0);
}

int calculate_parameters(int argc, char *argv[])
{
	int i;
	char **words;
	int counter_arguments;

	i = 1;
	counter_arguments = 0;
	while(i < argc)
	{
		words = ft_split(argv[i], ' ');
		if (check_validity(words, &counter_arguments) == 1)
		{
			return (0);
			free(words);
		}
		free(words);
		i++;
	}
	return (counter_arguments);
}

int	*allocate_and_validate(int argc, char *argv[], int *size)
{
	int	*array_int;
	int	counter;
	int	counter_for_array;
	char **words;
	int i;

	*size = calculate_parameters(argc, argv);
	if (*size == 0)
		return (NULL);
	array_int = malloc((*size) * sizeof(int));
	if (!array_int)
		return (NULL);
	counter = 1;
	counter_for_array = 0;
	while (counter < argc)
	{
		words = ft_split(argv[counter], ' ');
		i = 0;
		while(words[i] != NULL)
		{
			array_int[counter_for_array] = ft_atoi(words[i]);
			counter_for_array++;
			i++;
		}
		free(words);
		counter++;
	}
	return (array_int);
}

int	*process_arguments(int argc, char *argv[], int *size)
{
	int	*array_int;

	*size = 0;
	array_int = allocate_and_validate(argc, argv, size);
	if (!array_int)
		return (NULL);
	if (!check_for_duplicates(array_int, *size))
	{
		free(array_int);
		return (NULL);
	}
	return (array_int);
}

void	do_things(t_list *first_node_a)
{
	t_list	*first_node_b;
	int		is_sorted;
	int		counter;

	first_node_b = NULL;
	counter = 1;
	is_sorted = check_order_min_to_max(first_node_a);
	if (is_sorted == 1)
	{
		ft_lstclear(&first_node_a, free);
		return ;
	}
	apply_algorithm(&first_node_a, &first_node_b, counter);
	ft_lstclear(&first_node_a, free);
}
