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

void ra(t_list **first_node_a)
{
    t_list *tmp;
    t_list *last_node;

    tmp = (*first_node_a)->next;
    last_node = ft_lstlast(*first_node_a);
    ft_lstadd_back(first_node_a,*first_node_a);
    *first_node_a = tmp;
    last_node = last_node->next;
    last_node->next = NULL;
    // printf("%s\n","RA");
}

void rb(t_list **first_node_b)
{
    t_list *tmp;
    t_list *last_node;

    tmp = (*first_node_b)->next;
    last_node = ft_lstlast(*first_node_b);
    ft_lstadd_back(first_node_b,*first_node_b);
    *first_node_b = tmp;
    last_node = last_node->next;
    last_node->next = NULL;
    // printf("%s\n","RB");
}

void rr(t_list **first_node_a, t_list **first_node_b)
{
    ra(first_node_a);
    rb(first_node_b);
}

void rra(t_list **first_node_a)
{
    t_list *last_node;
    t_list *tmp;
    tmp = *first_node_a;
    last_node = ft_lstlast(*first_node_a);
    while(tmp->next != last_node)
    {
        tmp = tmp->next;
    }
    last_node->next = *first_node_a;
    tmp->next = NULL;
    *first_node_a = last_node;
}

void rrb(t_list **first_node_b)
{
    t_list *last_node;
    t_list *tmp;
    tmp = *first_node_b;
    last_node = ft_lstlast(*first_node_b);
    while(tmp->next != last_node)
    {
        tmp = tmp->next;
    }
    last_node->next = *first_node_b;
    tmp->next = NULL;
    *first_node_b = last_node;
}
