/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_check_order.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:39:16 by frocha            #+#    #+#             */
/*   Updated: 2024/11/11 23:39:17 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

int reverse_check_almost_min_to_max(t_list *first_node_a)
{
    t_list *tmp;
    t_list *second_node;

    tmp = ft_lstlast(first_node_a);
    second_node = first_node_a->next;
    while((second_node != tmp) && (*(int *)first_node_a->content < *(int *)second_node->content))
    {
        first_node_a = first_node_a->next;
        second_node = second_node->next;
    }
    if (second_node != tmp)
        return 0;
    else{
        return 1;
    }
}
