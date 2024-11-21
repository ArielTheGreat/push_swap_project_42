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

void  sort_back_to_a(t_list **stack_a, t_list **stack_b)
{
	int number_bottom_instructions;
	int number_top_instructions;
	t_list *biggest_number;

	while(ft_lstsize(*stack_b) != 0)
	{
		biggest_number = find_biggest_number(stack_b);
		number_bottom_instructions = bottom_instructions(stack_b, biggest_number);
		number_top_instructions = top_instructions(stack_b, biggest_number);
		if(number_top_instructions > number_bottom_instructions){
			while(number_bottom_instructions-- > 0)
				rrb(stack_b);
		}else{
			while(number_top_instructions-- > 0)
				rb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}

void apply_algorithm(t_list **stack_a, t_list **stack_b, int counter)
{
	int range;
	int index;
	t_list *temporal;

	range = (int)square_root(counter) * 1.4;
	index = 0;
	temporal = (*stack_a);
	while(temporal != NULL)
	{
		if (*(int *)temporal->content <= index)
		{
			pb(stack_b, stack_a);
			rb(stack_b);
			index++;
		}
		else if(*(int *)temporal->content <= index + range)
		{
			pb(stack_b, stack_a);
			index++;
		}
		else
			ra(stack_a);
		temporal = (*stack_a);
	}
	sort_back_to_a(stack_a, stack_b);
}