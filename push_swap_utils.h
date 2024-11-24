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

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	l_node;

void	swap(l_node **stack);
void	sa(l_node **a);
void	sb(l_node **b);
void	ss(l_node **a, l_node **b);
void	push(l_node **a, l_node **b);
void	pa(l_node **a, l_node **b);
void	pb(l_node **a, l_node **b);
void	rotate(l_node **stack);
void	ra(l_node **a);
void	rb(l_node **b);
void	rr(l_node **a, l_node **b);
void	reverse_rotate(l_node **stack);
void	rra(l_node **a);
void	rrb(l_node **b);
void	rrr(l_node **a, l_node **b);

void	sort_3(l_node **a);
int		find_min_value(l_node *stack);
int		find_min_index(l_node *stack, int min_value);
void	sort_to_5(l_node **first_node_a, l_node **first_node_b);
int		check_order_min_to_max(l_node *first_node);
void	do_things(l_node *first_node_a, int size);
l_node	*create_node(int index, int value);
void	order_array_quicksort(int *array_int, int length_array);
void	apply_algorithm(l_node **stack_a, l_node **stack_b, int counter);
l_node	*find_biggest_number(l_node **stack);
int		top_instructions(l_node **stack_b, l_node *biggest_number);
int		down_instructions(l_node **stack_b, l_node *biggest_number);
int		*process_arguments(int argc, char *argv[], int *size);
int		search_in_array(int *integer_list, int size, int value);
l_node	*create_and_link_nodes(int *array_int, int size, int *argv);
int		append_and_check(l_node **first_node, l_node **last_node,
			int index, int number);
int		ft_check_is_int(const char *str);
int		check_for_duplicates(int *array_int, int size);
void	free_arrays(int **array_int_sorted, int **array_int);
int		check_validity(char **elements, int *counter_arguments);
void	free_stack(l_node **stack);

#endif
