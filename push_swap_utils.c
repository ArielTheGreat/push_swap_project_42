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

t_stack	*create_node(int index, int value)
{
	t_stack	*n;
	
	n = malloc(sizeof(t_stack));
	if (!n)
		return (NULL);
	n->value = value;
	n->index = index;
	n->next = NULL;
	return (n);
}

int	square_root(int x)
{
	int	start;
	int	end;
	int	mid;
	int	ans;

	if (x == 0 || x == 1)
		return (x);
	start = 1;
	end = x / 2;
	ans = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (mid <= x / mid)
		{
			ans = mid;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	return (ans);
}

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	sort_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int		number_bottom_instructions;
	int		number_top_instructions;
	t_stack	*biggest_number;

	while (get_stack_size(*stack_b) != 0)
	{
		biggest_number = find_biggest_number(stack_b);
		number_bottom_instructions = down_instructions(stack_b, biggest_number);
		number_top_instructions = top_instructions(stack_b, biggest_number);
		if (number_top_instructions > number_bottom_instructions)
		{
			while (number_bottom_instructions--)
				rrb(stack_b);
		}
		else
		{
			while (number_top_instructions--)
				rb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}

void	apply_algorithm(t_stack **stack_a, t_stack **stack_b, int counter)
{
	int		range;
	int		index;
	t_stack	*temporal;

	range = (int)square_root(counter) * 1.4;
	index = 0;
	temporal = (*stack_a);
	while (temporal != NULL)
	{
		if (temporal->index <= index)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			index++;
		}
		else if (temporal->index <= index + range)
		{
			pb(stack_a, stack_b);
			index++;
		}
		else
			ra(stack_a);
		temporal = (*stack_a);
	}
	sort_back_to_a(stack_a, stack_b);
}
