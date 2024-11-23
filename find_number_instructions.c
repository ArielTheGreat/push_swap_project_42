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

int	down_instructions(t_list **stack_b, t_list *biggest_number)
{
	int		moves;
	t_list	*current;

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

int	top_instructions(t_list **stack_b, t_list *biggest_number)
{
	int		moves;
	t_list	*current;

	moves = 0;
	current = *stack_b;
	while (current != biggest_number)
	{
		current = current->next;
		moves++;
	}
	return (moves);
}

t_list	*find_biggest_number(t_list **stack)
{
	t_list	*current;
	t_list	*max_node;

	current = *stack;
	max_node = *stack;
	while (current)
	{
		if (*(int *)current->content > *(int *)max_node->content)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

int	append_node(t_list **first_node, t_list **last_node, int index)
{
	t_list	*new_node;

	new_node = create_node(index);
	if (!new_node)
		return (0);
	if (*first_node == NULL)
		*first_node = new_node;
	else
		(*last_node)->next = new_node;
	*last_node = new_node;
	return (1);
}

int	append_and_check(t_list **first_node, t_list **last_node,
	int *array_int, int number)
{
	int	index;
	int	array_size;

	array_size = 0;
	while (array_int[array_size] != '\0')
		array_size++;
	index = search_in_array(array_int, array_size, number);
	if (index == -1)
		return (0);
	return (append_node(first_node, last_node, index));
}
