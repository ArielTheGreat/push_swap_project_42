/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moving2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:33:43 by frocha            #+#    #+#             */
/*   Updated: 2024/11/11 23:33:45 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	rotate(l_node **stack)
{
	l_node	*first;
	l_node	*tmp;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		*stack = first->next;
		first->next = NULL;
		tmp->next = first;
	}
}

void	ra(l_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(l_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(l_node **a, l_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
