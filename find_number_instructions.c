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

int	down_instructions(l_node **stack_b, l_node *biggest_number)
{
	int		moves;
	l_node	*current;

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

int	top_instructions(l_node **stack_b, l_node *biggest_number)
{
	int		moves;
	l_node	*current;

	moves = 0;
	current = *stack_b;
	while (current != biggest_number)
	{
		current = current->next;
		moves++;
	}
	return (moves);
}

l_node	*find_biggest_number(l_node **stack)
{
	l_node	*current;
	l_node	*max_node;

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

int	append_node(l_node **first_node, l_node **last_node, int index, int value)
{
	l_node	*new_node;

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

int	append_and_check(l_node **first_node, l_node **last_node,
	int index, int number)
{
	return (append_node(first_node, last_node, index, number));
}
