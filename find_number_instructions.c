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

t_list	*create_and_link_nodes(int *array_int, int argc, char **argv)
{
	t_list	*first_node;
	t_list	*last_node;
	t_list	*new_node;
	int		counter;
	int		index;

	first_node = NULL;
	last_node = NULL;
	counter = 1;
	index = 0;
	while (counter < argc)
	{
		if (counter < argc)
			index = search_in_array(array_int, argc - 1, argv[counter]);
		if (index == -1)
		{
			ft_lstclear(&first_node, free);
			if (array_int && *array_int)
				free(array_int);
			return (NULL);
		}
		new_node = create_node(index);
		if (!new_node)
		{
			ft_lstclear(&first_node, free);
			return (NULL);
		}
		if (counter == 1)
			first_node = new_node;
		else
			last_node->next = new_node;
		last_node = new_node;
		counter++;
	}
	return (first_node);
}
