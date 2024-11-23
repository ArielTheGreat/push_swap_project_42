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
# include <limits.h>
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
void	do_things(t_list *first_node_a);
t_list	*create_node(int number_char);
void	order_array_quicksort(int *array_int, int length_array);
void	apply_algorithm(t_list **stack_a, t_list **stack_b, int counter);
t_list	*find_biggest_number(t_list **stack);
int		top_instructions(t_list **stack_b, t_list *biggest_number);
int		down_instructions(t_list **stack_b, t_list *biggest_number);
int		*process_arguments(int argc, char *argv[], int *size);
int		search_in_array(int *integer_list, int size, int value);
t_list	*create_and_link_nodes(int *array_int, int argc, int *argv);
int		append_and_check(t_list **first_node, t_list **last_node,
			int *array_int, int number);
int		ft_check_is_int(const char *str);
int		check_for_duplicates(int *array_int, int size);

#endif
