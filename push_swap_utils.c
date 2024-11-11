/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:46:57 by frocha            #+#    #+#             */
/*   Updated: 2024/11/11 18:46:59 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void rrr(t_list **first_node_a, t_list **first_node_b)
{
    rra(first_node_a);
    rrb(first_node_b);
}

t_list *create_node(int number_char)
{
    t_list *n;
    int    *number;

    number = malloc(sizeof(int));
    if (!number)
        return (NULL); 
    *number = number_char;
    n = malloc(sizeof(t_list));
    if (!n)
    {
        free(number);
        return (NULL);
    }
    n->content = (void *)number;
    n->next = NULL;
    return (n);
}

void	move_to_stack_b(t_list **stack_a, t_list **stack_b, int midpoint, int *count_instructions)
{
	int	current_value;

	current_value = *(int *)(*stack_a)->content;
	if (current_value < midpoint)
	{
		pb(stack_b, stack_a);
		if (current_value < midpoint / 2)
			rb(stack_b);
	}
	else
		ra(stack_a);
	(*count_instructions)++;
}

void	empty_stack_b(t_list **stack_a, t_list **stack_b, int *count_instructions)
{
	while (*stack_b != NULL)
	{
		pa(stack_a, stack_b);
		(*count_instructions)++;
	}
}

void	chunked_quick_sort(t_list **stack_a, t_list **stack_b, int counter)
{
	int	count_instructions;
	int	midpoint;
	int	i;

	count_instructions = 0;
	while (counter / 4 > 1)
	{
		midpoint = counter / 2;
		i = -1;
		while (++i < counter)
			move_to_stack_b(stack_a, stack_b, midpoint, &count_instructions);
		empty_stack_b(stack_a, stack_b, &count_instructions);
		counter /= 2;
	}
	printf("Total Instructions: %d\n", count_instructions);
}
