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

void sa(t_list *first_node_a)
{
    t_list *second_node_a;
    void    *value_first_element;

    second_node_a = NULL;
    if (first_node_a == NULL || !first_node_a->next)
    {
        return;
    }
    value_first_element = first_node_a->content;
    second_node_a = first_node_a->next;
    first_node_a->content = second_node_a->content;
    second_node_a->content = value_first_element;
    // printf("%s\n","SA");
}

void sb(t_list *first_node_b)
{
    t_list *second_node_b;
    void   *value_first_element;

    second_node_b = NULL;
    if (first_node_b == NULL || !(first_node_b->next))
    {
        return;
    }
    second_node_b = first_node_b->next;
    value_first_element =  first_node_b->content;
    first_node_b->content = second_node_b->content;
    second_node_b->content = value_first_element;
    // printf("%s\n","SB");
}

void ss(t_list *first_node_a, t_list *first_node_b)
{
    sa(first_node_a);
    sb(first_node_b);
}

void pa(t_list **first_node_a, t_list **first_node_b)
{
    t_list *tmp;
    if (!first_node_b)
        return;

    tmp = (*first_node_b)->next;
    ft_lstadd_front(first_node_a, *first_node_b);
    *first_node_b = tmp;
    // printf("%s\n","PA");
}

void pb(t_list **first_node_b, t_list **first_node_a)
{
    t_list *tmp;
    if (!first_node_a)
        return;

    tmp = (*first_node_a)->next;
    ft_lstadd_front(first_node_b, *first_node_a);
    *first_node_a = tmp;
    // printf("%s\n","PB");
}

void ra(t_list **first_node_a)
{
    t_list *tmp;
    t_list *last_node;

    tmp = (*first_node_a)->next;
    last_node = ft_lstlast(*first_node_a);
    ft_lstadd_back(first_node_a,*first_node_a);
    *first_node_a = tmp;
    last_node = last_node->next;
    last_node->next = NULL;
    // printf("%s\n","RA");
}

void rb(t_list **first_node_b)
{
    t_list *tmp;
    t_list *last_node;

    tmp = (*first_node_b)->next;
    last_node = ft_lstlast(*first_node_b);
    ft_lstadd_back(first_node_b,*first_node_b);
    *first_node_b = tmp;
    last_node = last_node->next;
    last_node->next = NULL;
    // printf("%s\n","RB");
}

void rr(t_list **first_node_a, t_list **first_node_b)
{
    ra(first_node_a);
    rb(first_node_b);
}

void rra(t_list **first_node_a)
{
    t_list *last_node;
    t_list *tmp;
    tmp = *first_node_a;
    last_node = ft_lstlast(*first_node_a);
    while(tmp->next != last_node)
    {
        tmp = tmp->next;
    }
    last_node->next = *first_node_a;
    tmp->next = NULL;
    *first_node_a = last_node;
}

void rrb(t_list **first_node_b)
{
    t_list *last_node;
    t_list *tmp;
    tmp = *first_node_b;
    last_node = ft_lstlast(*first_node_b);
    while(tmp->next != last_node)
    {
        tmp = tmp->next;
    }
    last_node->next = *first_node_b;
    tmp->next = NULL;
    *first_node_b = last_node;
}

void rrr(t_list **first_node_a, t_list **first_node_b)
{
    rra(first_node_a);
    rrb(first_node_b);
}

int check_order_min_to_max(t_list *first_node)
{
    t_list *second_node;

    second_node = first_node->next;
    while((second_node != NULL) && (*(int *)second_node->content > *(int *)first_node->content))
    {
        first_node = first_node->next;
        second_node = second_node->next;
    }
    if (second_node != NULL)
        return 0;
    else{
        return 1;
    }
}

int check_almost_order_min_to_max(t_list *first_node)
{
    t_list *second_node;
    t_list *third_element;
    t_list *last_element;

    second_node = first_node->next;
    third_element = second_node->next;
    last_element = ft_lstlast(first_node);

    while(second_node->next != last_element && (*(int *)second_node->content < *(int *)third_element->content))
    {
        second_node = second_node->next;
        third_element = third_element->next;
    }
    if (*(int *)first_node->content < *(int *)second_node->content)
    {
        return 0;
    }
    if (second_node->next != last_element)
        return 0;
    else{
        printf("%s\n","ALMOST ORDERED MIN TO MAX");
        return 1;
    }
}

int check_order_max_to_min(t_list *first_node)
{
    t_list *second_node;

    second_node = first_node->next;
    while((second_node != NULL) && (*(int *)second_node->content < *(int *)first_node->content))
    {
        first_node = first_node->next;
        second_node = second_node->next;
    }
    if (second_node != NULL)
        return 0;
    else{
        return 1;
    }
}

int check_almost_order_max_to_min(t_list *first_node)
{
    t_list *second_node;
    t_list *third_element;
    t_list *last_element;

    second_node = first_node->next;
    third_element = second_node->next;
    last_element = ft_lstlast(first_node);

    while(second_node->next != last_element && (*(int *)second_node->content > *(int *)third_element->content))
    {
        second_node = second_node->next;
        third_element = third_element->next;
    }
    if (*(int *)first_node->content > *(int *)second_node->content)
    {
        return 0;
    }
    if (second_node->next != last_element)
        return 0;
    else{
        printf("%s\n","ALMOST ORDERED MAX TO MIN");
        return 1;
    }
}

int reverse_check_almost_max_to_min(t_list *first_node_b)
{
    t_list *tmp;
    t_list *second_node;

    tmp = ft_lstlast(first_node_b);
    second_node = first_node_b->next;
    while((second_node != tmp) && (*(int *)first_node_b->content > *(int *)second_node->content))
    {
        first_node_b = first_node_b->next;
        second_node = second_node->next;
    }
    if (second_node != tmp)
        return 0;
    else{
        return 1;
    }
}

int reverse_check_almost_min_to_max(t_list *first_node_a)
{
    t_list *tmp;
    t_list *second_node;

    tmp = ft_lstlast(first_node_a);
    second_node = first_node_a->next;
    while((second_node != tmp) && (*(int *)first_node_a->content < *(int *)second_node->content))
    {
        first_node_a = first_node_a->next;
        second_node = second_node->next;
    }
    if (second_node != tmp)
        return 0;
    else{
        return 1;
    }
}

void divide_into_stacks(t_list **first_node_a,t_list **first_node_b, float midpoint, int *counter_instructions)
{
    t_list *last_node;
    
    last_node = ft_lstlast(*first_node_a);
    while(*first_node_a != last_node)
    {
        if (*(int *)(*first_node_a)->content < midpoint )
        {
            pb(first_node_b, first_node_a);
            *(counter_instructions) = *(counter_instructions) + 1;
        }
        else{
            ra(first_node_a);
            *(counter_instructions) = *(counter_instructions) + 1;
        }
    }
    if (*(int *)(*first_node_a)->content < midpoint )
    {
        pb(first_node_b, first_node_a);
        *(counter_instructions) = *(counter_instructions) + 1;
    }
}

void apply_instructions_to_b(t_list **first_node_b, int *counter_instructions)
{
    t_list *second_node;
    t_list *last_node;

    if ((*first_node_b)->next == NULL)
        return;
    while(check_order_max_to_min(*first_node_b) != 1)
    {
        second_node = (*first_node_b)->next;
        last_node = ft_lstlast(*first_node_b);
        
        if (check_order_max_to_min(second_node) == 1 && *(int *)(*first_node_b)->content < *(int *)last_node->content)
        {
            rb(first_node_b);
            *(counter_instructions) = *(counter_instructions) + 1;
        }else if(reverse_check_almost_max_to_min(*first_node_b) == 1)
        {
            rrb(first_node_b);
            *(counter_instructions) = *(counter_instructions) + 1;
        }else if(*(int *)last_node->content < *(int *)(*first_node_b)->content && *(int *)last_node->content > *(int *)second_node->content)
        {
            rrb(first_node_b);
            sb(*first_node_b);
            *(counter_instructions) = *(counter_instructions) + 2;
        }
        else if (check_almost_order_max_to_min(*first_node_b) && *(int *)last_node->content > *(int *)(*first_node_b)->content)
        {
            rrb(first_node_b);
            *(counter_instructions) = *(counter_instructions) + 1;
            if (check_order_max_to_min(*first_node_b) == 1)
                break;
            sb(*first_node_b);
            rb(first_node_b);
            *(counter_instructions) = *(counter_instructions) + 2;
        }
        else if (*(int *)(*first_node_b)->content < *(int *)second_node->content)
        {
            sb(*first_node_b);
            *(counter_instructions) = *(counter_instructions) + 1;
        }
        else
        {
            rb(first_node_b);
            *(counter_instructions) = *(counter_instructions) + 1;
        }
    }
}

void apply_instructions_to_a(t_list **first_node_a, int *counter_instructions)
{
    t_list *second_node;
    t_list *last_node;

    if (!((*first_node_a)->next))
        return;
    while(check_order_min_to_max(*first_node_a) != 1)
    {
        second_node = (*first_node_a)->next;
        last_node = ft_lstlast(*first_node_a);
        if (check_order_min_to_max(second_node) == 1 && *(int *)(*first_node_a)->content > *(int *)last_node->content)
        {
            ra(first_node_a);
            *(counter_instructions) = *(counter_instructions) + 1;
        }else if(reverse_check_almost_min_to_max(*first_node_a) == 1)
        {
            rra(first_node_a);
            *(counter_instructions) = *(counter_instructions) + 1;
        }else if(*(int *)last_node->content > *(int *)(*first_node_a)->content && *(int *)last_node->content < *(int *)second_node->content)
        {
            rra(first_node_a);
            sa(*first_node_a);
            *(counter_instructions) = *(counter_instructions) + 2;
        }
        else if (check_almost_order_min_to_max(*first_node_a) && *(int *)last_node->content < *(int *)(*first_node_a)->content)
        {
            rra(first_node_a);
            *(counter_instructions) = *(counter_instructions) + 1;
            if (check_order_min_to_max(*first_node_a) == 1)
                break;
            sa(*first_node_a);
            ra(first_node_a);
            *(counter_instructions) = *(counter_instructions) + 2;
        }else if (*(int *)(*first_node_a)->content > *(int *)second_node->content)
        {
            sa(*first_node_a);
            *(counter_instructions) = *(counter_instructions) + 1;
        }
        else
        {
            ra(first_node_a);
            *(counter_instructions) = *(counter_instructions) + 1;
        }
    }
}
