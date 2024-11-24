/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:05:50 by frocha            #+#    #+#             */
/*   Updated: 2024/11/21 18:05:51 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

int	check_for_duplicates(int *array_int, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array_int[i] == array_int[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_is_int(const char *str)
{
	int		sign;
	long	result;
	int		i;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > (LONG_MAX - (str[i] - '0')) / 10)
			return (0);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result *= sign;
	if (result > INT_MAX || result < INT_MIN)
		return (0);
	return (1);
}

t_list	*create_and_link_nodes(int *array_int, int argc, int *argv)
{
	t_list	*first_node;
	t_list	*last_node;
	int		counter;

	first_node = NULL;
	last_node = NULL;
	counter = 0;
	while (counter < argc)
	{
		if (!append_and_check(&first_node, &last_node,
				array_int, argv[counter]))
		{
			ft_lstclear(&first_node, free);
			if (array_int && *array_int)
				free(array_int);
			return (NULL);
		}
		counter++;
	}
	return (first_node);
}

int	main(int argc, char *argv[])
{
	int		*array_int_sorted;
	int		*array_int;
	t_list	*first_node;
	int size;
	int i;

	i = 0;
	if (argc < 2)
		return (0);
	array_int = process_arguments(argc, argv, &size);
	if (array_int)
	{
		array_int_sorted = malloc((size) * sizeof(int));
		while(i < size)
		{
			array_int_sorted[i] = array_int[i];
			i++;
		}
		order_array_quicksort(array_int_sorted, size);
	}
	if (!array_int)
	{
		write(stderr, "Error\n", 6);
		return (1);
	}
	first_node = create_and_link_nodes(array_int_sorted, size, array_int);
	if (!first_node)
	{
		free(array_int_sorted);
		return (1);
	}
	free(array_int_sorted);
	free(array_int);
	do_things(first_node);
	return (0);
}
