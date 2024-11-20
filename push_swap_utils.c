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

void	rrr(t_list **first_node_a, t_list **first_node_b)
{
	rra(first_node_a);
	rrb(first_node_b);
}

t_list	*create_node(int number_char)
{
	t_list	*n;
	int		*number;

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

void	move_to_stack_b(t_list **stack_a, t_list **stack_b,
						int midpoint, int *count_instructions)
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

void	empty_stack_b(t_list **stack_a, t_list **stack_b,
		int *count_instructions)
{
	while (*stack_b != NULL)
	{
		pa(stack_a, stack_b);
		(*count_instructions)++;
	}
}

int square_root(int x) {
    if (x == 0 || x == 1)
        return x;

    int start = 1, end = x / 2, ans = 0;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (mid <= x / mid) {
            ans = mid;   
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int find_bigger(t_list **stack_b)
{
	int first_number;

	first_number = 0;
	
}

void sort_back_to_a(t_list **stack_a, t_list **stack_b)
{
	int max_size_int;

	while(ft_lstsize(*stack_b) != 0)
	{
		max_size_int = find_bigger(stack_b);

		pa(stack_a, stack_b);
	}
}

void apply_algorithm(t_list **stack_a, t_list **stack_b, int counter)
{
	int range;
	int index;

	range = square_root(counter) * 18 / 10;
	index = 0;
	while(*stack_a != NULL)
	{
		if (*(int *)(*stack_a)->content <= index)
		{
			pb(stack_b, stack_a);
			rb(stack_b);
			index++;
		}
		else if(*(int *)(*stack_a)->content <= index + range)
		{
			pb(stack_b, stack_a);
			index++;
		}
		else{
			ra(stack_a);
		}
	}
	sort_back_to_a(stack_a, stack_b);
}