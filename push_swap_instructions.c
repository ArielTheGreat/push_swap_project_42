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

void	sa(t_list *first_node_a)
{
	t_list	*second_node_a;
	void	*value_first_element;

	second_node_a = NULL;
	if (first_node_a == NULL || !first_node_a->next)
		return ;
	value_first_element = first_node_a->content;
	second_node_a = first_node_a->next;
	first_node_a->content = second_node_a->content;
	second_node_a->content = value_first_element;
	write(1, "sa\n", 3);
}

void	sb(t_list *first_node_b)
{
	t_list	*second_node_b;
	void	*value_first_element;

	second_node_b = NULL;
	if (first_node_b == NULL || !first_node_b->next)
		return ;
	second_node_b = first_node_b->next;
	value_first_element = first_node_b->content;
	first_node_b->content = second_node_b->content;
	second_node_b->content = value_first_element;
	write(1, "sb\n", 3);
}

void	ss(t_list *first_node_a, t_list *first_node_b)
{
	sa(first_node_a);
	sb(first_node_b);
	write(1, "ss\n", 3);
}

void	pa(t_list **first_node_a, t_list **first_node_b)
{
	t_list	*tmp;

	if (!first_node_b || !*first_node_b)
		return ;
	tmp = (*first_node_b)->next;
	ft_lstadd_front(first_node_a, *first_node_b);
	*first_node_b = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_list **first_node_b, t_list **first_node_a)
{
	t_list	*tmp;

	if (!first_node_a || !*first_node_a)
		return ;
	tmp = (*first_node_a)->next;
	ft_lstadd_front(first_node_b, *first_node_a);
	*first_node_a = tmp;
	write(1, "pb\n", 3);
}
