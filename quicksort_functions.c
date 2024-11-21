/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:20:19 by frocha            #+#    #+#             */
/*   Updated: 2024/11/21 16:20:21 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int *array_int, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array_int[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (array_int[j] <= pivot)
		{
			i++;
			swap(&array_int[i], &array_int[j]);
		}
		j++;
	}
	swap(&array_int[i + 1], &array_int[high]);
	return (i + 1);
}

void	quicksort(int *array_int, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(array_int, low, high);
		quicksort(array_int, low, pi - 1);
		quicksort(array_int, pi + 1, high);
	}
}

void	order_array_quicksort(int *array_int, int length_array)
{
	quicksort(array_int, 0, length_array - 1);
}
