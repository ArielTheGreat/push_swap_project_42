/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moving.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:32:26 by frocha            #+#    #+#             */
/*   Updated: 2024/11/11 23:32:28 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	swap(l_node **stack)
{
	l_node	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *stack;
		*stack = tmp;
	}
}

void	sa(l_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(l_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(l_node **a, l_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
