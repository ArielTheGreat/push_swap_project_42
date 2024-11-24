/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:51:48 by frocha            #+#    #+#             */
/*   Updated: 2024/11/24 17:51:50 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	push(l_node **src, l_node **dest)
{
	l_node	*tmp;

	if (*src)
	{
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dest;
		*dest = tmp;
	}
}

void	pa(l_node **a, l_node **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(l_node **a, l_node **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
