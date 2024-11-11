/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:38:00 by frocha            #+#    #+#             */
/*   Updated: 2024/11/11 23:38:01 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

int check_order_min_to_max(t_list *first_node)
{
    t_list *second_node;

    second_node = first_node->next;
    while((second_node != NULL) && (*(int *)second_node->content > *(int *)first_node->content))
    {
        first_node = first_node->next;
        second_node = second_node->next;
    }
    if (second_node != NULL)
        return 0;
    else{
        return 1;
    }
}
