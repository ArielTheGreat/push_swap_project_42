/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:47:06 by frocha            #+#    #+#             */
/*   Updated: 2024/11/11 18:47:08 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
#define PUSH_SWAP_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

void sa(t_list *first_node_a);
void sb(t_list *first_node_b);
void ss(t_list *first_node_a, t_list *first_node_b);
void pa(t_list **first_node_a, t_list **first_node_b);
void pb(t_list **first_node_b, t_list **first_node_a);
void ra(t_list **first_node_a);
void rb(t_list **first_node_b);
void rr(t_list **first_node_a, t_list **first_node_b);
void rra(t_list **first_node_a);
void rrb(t_list **first_node_b);
void rrr(t_list **first_node_a, t_list **first_node_b);
int check_order_min_to_max(t_list *first_node);
int check_almost_order_min_to_max(t_list *first_node);
int reverse_check_almost_min_to_max(t_list *first_node);
int check_order_max_to_min(t_list *first_node);
int check_almost_order_max_to_min(t_list *first_node);
int reverse_check_almost_max_to_min(t_list *first_node);
void divide_into_stacks(t_list **first_node_a,t_list **first_node_b, float midpoint, int *counter_instructions);
void apply_instructions_to_b(t_list **first_node_b, int *counter_instructions);
void apply_instructions_to_a(t_list **first_node_a, int *counter_instructions);

#endif
