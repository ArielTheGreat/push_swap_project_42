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
}	t_node;

void	swap(t_node **stack);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	push(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	rotate(t_node **stack);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	reverse_rotate(t_node **stack);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

void	sort_3(t_node **a);
int		find_min_value(t_node *stack);
int		find_min_index(t_node *stack, int min_value);
void	sort_to_5(t_node **first_node_a, t_node **first_node_b);
int		check_order_min_to_max(t_node *first_node);
void	process_and_sort_stack(t_node *first_node_a, int size);
t_node	*create_node(int index, int value);
void	order_array_quicksort(int *array_int, int length_array);
void	apply_algorithm(t_node **stack_a, t_node **stack_b, int counter);
t_node	*find_biggest_number(t_node **stack);
int		top_instructions(t_node **stack_b, t_node *biggest_number);
int		down_instructions(t_node **stack_b, t_node *biggest_number);
int		*process_arguments(int argc, char *argv[], int *size);
int		search_in_array(int *integer_list, int size, int value);
t_node	*create_and_link_nodes(int *array_int, int size, int *argv);
int		append_and_check(t_node **first_node, t_node **last_node,
			int index, int number);
int		ft_check_is_int(const char *str);
int		check_for_duplicates(int *array_int, int size);
void	free_arrays(int **array_int_sorted, int **array_int);
int		check_validity(char **elements, int *counter_arguments);
void	free_stack(t_node **stack);

#endif
