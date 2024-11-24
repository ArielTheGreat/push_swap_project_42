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

t_stack	*create_and_link_nodes(int *array_int_sorted, int size, int *array_int)
{
	t_stack	*first_node;
	t_stack	*last_node;
	int		counter;
	int		index;

	first_node = NULL;
	last_node = NULL;
	counter = 0;
	while (counter < size)
	{
		index = search_in_array(array_int_sorted, size, array_int[counter]);
		if (index == -1)
			return (NULL);
		if (!append_and_check(&first_node, &last_node,
				index, array_int[counter]))
		{
			free_stack(&first_node);
			if (array_int_sorted && *array_int_sorted)
				free(array_int_sorted);
			return (NULL);
		}
		counter++;
	}
	return (first_node);
}

void	allocate_sorted_array(int **array_int_sorted, int size, int *array_int)
{
	int	i;

	i = 0;
	*array_int_sorted = malloc(size * sizeof(int));
	if (!*array_int_sorted)
		return ;
	while (i < size)
	{
		(*array_int_sorted)[i] = array_int[i];
		i++;
	}
	order_array_quicksort(*array_int_sorted, size);
}

int	main(int argc, char *argv[])
{
	int		*array_int_sorted;
	int		*array_int;
	t_stack	*first_node;
	int		size;

	array_int_sorted = NULL;
	if (argc < 2)
		return (0);
	array_int = process_arguments(argc, argv, &size);
	if (array_int)
		allocate_sorted_array(&array_int_sorted, size, array_int);
	else
	{
		write(2, "Error\n", 6);
		return (1);
	}
	first_node = create_and_link_nodes(array_int_sorted, size, array_int);
	if (!first_node)
	{
		free(array_int_sorted);
		return (1);
	}
	free_arrays(&array_int_sorted, &array_int);
	do_things(first_node, size);
	return (0);
}
