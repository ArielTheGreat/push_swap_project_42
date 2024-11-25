/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arrays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:08:00 by frocha            #+#    #+#             */
/*   Updated: 2024/11/24 12:08:02 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	free_arrays(int **array_int_sorted, int **array_int)
{
	free(*array_int_sorted);
	*array_int_sorted = NULL;
	free(*array_int);
	*array_int = NULL;
}

void	free_split_arrays(char **words)
{
	int		i;

	i = 0;
	while (words[i] != NULL)
	{
		free(words[i]);
		i++;
	}
	free(words);
}
