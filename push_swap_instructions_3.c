/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions_3.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:14:39 by frocha            #+#    #+#             */
/*   Updated: 2024/11/21 16:14:42 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*stack && (*stack)->next)
	{
		last = *stack;
		while (last->next)
		{
			second_last = last;
			last = last->next;
		}
		second_last->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
