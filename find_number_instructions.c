/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_number_instructions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:00:36 by frocha            #+#    #+#             */
/*   Updated: 2024/11/21 16:00:38 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

int	down_instructions(t_stack **stack_b, t_stack *biggest_number)
{
	int		moves;
	t_stack	*current;

	moves = 0;
	current = *stack_b;
	while (current != biggest_number)
		current = current->next;
	while (current)
	{
		current = current->next;
		moves++;
	}
	return (moves);
}

int	top_instructions(t_stack **stack_b, t_stack *biggest_number)
{
	int		moves;
	t_stack	*current;

	moves = 0;
	current = *stack_b;
	while (current != biggest_number)
	{
		current = current->next;
		moves++;
	}
	return (moves);
}

t_stack	*find_biggest_number(t_stack **stack)
{
	t_stack	*current;
	t_stack	*max_node;

	current = *stack;
	max_node = *stack;
	while (current)
	{
		if (current->value > max_node->value)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

int	append_node(t_stack **first_node, t_stack **last_node, int index, int value)
{
	t_stack	*new_node;

	new_node = create_node(index, value);
	if (!new_node)
		return (0);
	if (*first_node == NULL)
		*first_node = new_node;
	else
		(*last_node)->next = new_node;
	*last_node = new_node;
	return (1);
}

int	append_and_check(t_stack **first_node, t_stack **last_node,
	int *array_int_sorted, int number)
{
	int	index;
	int	array_size;

	array_size = 0;
	while (array_int_sorted[array_size] != '\0')
		array_size++;
	index = search_in_array(array_int_sorted, array_size, number);
	if (index == -1)
		return (0);
	return (append_node(first_node, last_node, index, number));
}
