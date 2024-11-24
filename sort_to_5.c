/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:55:51 by frocha            #+#    #+#             */
/*   Updated: 2024/11/24 18:55:52 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	move_min_to_b(t_node **a, t_node **b, int *size)
{
	int	min_value;
	int	min_index;

	min_value = find_min_value(*a);
	min_index = find_min_index(*a, min_value);
	while ((*a)->value != min_value)
	{
		if (min_index <= *size / 2)
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
	(*size)--;
}

int	get_elements_to_move(int size)
{
	if (size == 5)
		return (2);
	return (1);
}

void	sort_to_5(t_node **a, t_node **b)
{
	int		size;
	int		elements_to_move;
	t_node	*temp;

	size = 0;
	temp = *a;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	elements_to_move = get_elements_to_move(size);
	while (elements_to_move > 0)
	{
		move_min_to_b(a, b, &size);
		elements_to_move--;
	}
	sort_3(a);
	while (*b)
		pa(a, b);
}
