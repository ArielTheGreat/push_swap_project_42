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

void chunked_quick_sort(t_list **stack_a, t_list **stack_b, int counter) 
{
    int count_instructions;
    int chunk_size;
    int i;
    int midpoint;
    int current_value;
    
    count_instructions = 0;
    chunk_size = counter / 4;
    while (chunk_size > 1) {
        midpoint = counter / 2;
        i = 0;
        while (i < counter) {
            current_value = *(int *)(*stack_a)->content;
            if (current_value < midpoint) {
                pb(stack_b, stack_a);
                if (current_value < midpoint / 2)
                    rb(stack_b);
            } else
                ra(stack_a);
            count_instructions++;
            i++;
        }
        while (*stack_b != NULL) 
        {
            pa(stack_a, stack_b);
            count_instructions++;
        }
        chunk_size /= 2;
    }
    printf("Total Instructions: %d\n", count_instructions);
}

void do_things(t_list *first_node_a, int counter) {
    t_list *first_node_b;
    int is_sorted;
    
    first_node_b = NULL;
    is_sorted = check_order_min_to_max(first_node_a);
    if (is_sorted == 1) return;
    chunked_quick_sort(&first_node_a, &first_node_b, counter);
    ft_lstclear(&first_node_a, free);
}
