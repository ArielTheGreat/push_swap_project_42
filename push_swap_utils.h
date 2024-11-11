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
# define PUSH_SWAP_UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

void	sa(t_list *first_node_a);
void	sb(t_list *first_node_b);
void	ss(t_list *first_node_a, t_list *first_node_b);
void	pa(t_list **first_node_a, t_list **first_node_b);
void	pb(t_list **first_node_b, t_list **first_node_a);
void	ra(t_list **first_node_a);
void	rb(t_list **first_node_b);
void	rr(t_list **first_node_a, t_list **first_node_b);
void	rra(t_list **first_node_a);
void	rrb(t_list **first_node_b);
void	rrr(t_list **first_node_a, t_list **first_node_b);

int		check_order_min_to_max(t_list *first_node);
void	do_things(t_list *first_node_a, int counter);
t_list	*create_node(int number_char);
void	order_array_quicksort(int *array_int, int length_array);
void	chunked_quick_sort(t_list **stack_a, t_list **stack_b, int counter);

#endif
