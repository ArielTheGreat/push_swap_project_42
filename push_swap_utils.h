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

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	push(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

int		check_order_min_to_max(t_stack *first_node);
void	do_things(t_stack *first_node_a);
t_stack	*create_node(int index, int value);
void	order_array_quicksort(int *array_int, int length_array);
void	apply_algorithm(t_stack **stack_a, t_stack **stack_b, int counter);
t_stack	*find_biggest_number(t_stack **stack);
int		top_instructions(t_stack **stack_b, t_stack *biggest_number);
int		down_instructions(t_stack **stack_b, t_stack *biggest_number);
int		*process_arguments(int argc, char *argv[], int *size);
int		search_in_array(int *integer_list, int size, int value);
t_stack	*create_and_link_nodes(int *array_int, int argc, int *argv);
int		append_and_check(t_stack **first_node, t_stack **last_node,
			int *array_int, int number);
int		ft_check_is_int(const char *str);
int		check_for_duplicates(int *array_int, int size);
void	free_arrays(int **array_int_sorted, int **array_int);
int		check_validity(char **elements, int *counter_arguments);
void	free_stack(t_stack **stack);

#endif
