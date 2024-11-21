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

void	ra(t_list **first_node_a)
{
	if (!*first_node_a || !(*first_node_a)->next)
		return;

	t_list	*tmp = (*first_node_a)->next;
	t_list	*last_node = ft_lstlast(*first_node_a);

	last_node->next = *first_node_a;
	(*first_node_a)->next = NULL;
	*first_node_a = tmp;

	//printf("RA\n");
}

void	rb(t_list **first_node_b)
{
	if (!*first_node_b || !(*first_node_b)->next)
		return;

	t_list	*tmp = (*first_node_b)->next;
	t_list	*last_node = ft_lstlast(*first_node_b);

	last_node->next = *first_node_b;
	(*first_node_b)->next = NULL;
	*first_node_b = tmp;

	//printf("RB\n");
}

void	rr(t_list **first_node_a, t_list **first_node_b)
{
	ra(first_node_a);
	rb(first_node_b);
}

void	rra(t_list **first_node_a)
{
	if (!*first_node_a || !(*first_node_a)->next)
		return;

	t_list	*last_node = ft_lstlast(*first_node_a);
	t_list	*tmp = *first_node_a;

	while (tmp->next != last_node)
		tmp = tmp->next;
	
	last_node->next = *first_node_a;
	tmp->next = NULL;
	*first_node_a = last_node;

	printf("RRA\n");
}

void	rrb(t_list **first_node_b)
{
	if (!*first_node_b || !(*first_node_b)->next)
		return;

	t_list	*last_node = ft_lstlast(*first_node_b);
	t_list	*tmp = *first_node_b;

	while (tmp->next != last_node)
		tmp = tmp->next;

	last_node->next = *first_node_b;
	tmp->next = NULL;
	*first_node_b = last_node;

	//printf("RRB\n");
}
