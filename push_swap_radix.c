/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:46:37 by frocha            #+#    #+#             */
/*   Updated: 2024/11/11 18:46:39 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

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

void print_content(void *node)
{
    printf("%i ",*(int *)node);
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
    ft_lstiter(first_node_a, print_content);
    ft_lstclear(&first_node_a, free);
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* array_int, int low, int high) {
    int pivot = array_int[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array_int[j] <= pivot) {
            i++;
            swap(&array_int[i], &array_int[j]);
        }
    }

    swap(&array_int[i + 1], &array_int[high]);
    return i + 1;
}

void quicksort(int* array_int, int low, int high) {
    if (low < high) {
        int pi = partition(array_int, low, high);

        quicksort(array_int, low, pi - 1);
        quicksort(array_int, pi + 1, high);
    }
}

void order_array_quicksort(int *array_int,int length_array)
{
    quicksort(array_int, 0, length_array - 1);
}

int search_in_array(int *integer_list,char *value)
{
    int counter;
    int integer;

    integer = ft_atoi(value);
    counter = 0;
    while(integer_list[counter] != integer){
        counter++;
    }
    return counter;
}

int main(int argc, char *argv[])
{
    int counter;
    t_list *first_node;
    t_list *last_node;
    t_list *new_node;
    int counter_for_array;

    if (argc < 2)
        return (0);

    first_node = NULL;
    last_node = NULL;
    counter = 1;
    counter_for_array = 0;
    int *array_int = malloc((argc-1) * sizeof(int));
    if (!array_int)
        return (1);

    while (counter < argc)
        array_int[counter_for_array++] = ft_atoi(argv[counter++]);

    order_array_quicksort(array_int, argc-1);
    counter = 1;
    while (counter < argc)
    {
        new_node = create_node(search_in_array(array_int, argv[counter]));
        if (!new_node)
        {
            ft_lstclear(&first_node, free);
            return (1);
        }

        if (counter == 1)
            first_node = new_node;
        else
            last_node->next = new_node;
        last_node = new_node;
        counter++;
    }
    do_things(first_node, counter - 1);
    free(array_int);
    return (0);
}
