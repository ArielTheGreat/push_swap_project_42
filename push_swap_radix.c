#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
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

void apply_radix_push_swap(t_list **first_node_a, t_list **first_node_b, int counter)
{
    int i;
    int temporal_value_bits;
    int counterOuter;
    int flag;
    int counterInstructions;

    i = 0;
    counterOuter = 0;
    counterInstructions = 0;
    while(counterOuter < 32)
    {
        flag = 0;
        i = 0;
        while(i < counter)
        {
            temporal_value_bits = *(int *)(*first_node_a)->content >> counterOuter;
            if((temporal_value_bits & 1) == flag)
            {
                pb(first_node_b, first_node_a);
                printf("%s\n","PB");
                counterInstructions++;
            }else{
                ra(first_node_a);
                printf("%s\n","RA");
                counterInstructions++;
            }
            i++;
        }
        while(*first_node_b != NULL)
        {
            pa(first_node_a, first_node_b);
            printf("%s\n","PA");
            counterInstructions++;
        }
        if (check_order_min_to_max(*first_node_a))
            break;
        counterOuter++;
    }
    printf("%i\n",counterInstructions);
}

void do_things(t_list *first_node_a, int counter)
{
    t_list *first_node_b;
    int numerical_val;

    first_node_b = NULL;
    numerical_val = check_order_min_to_max(first_node_a);
    if (numerical_val == 1)
        return;
    apply_radix_push_swap(&first_node_a, &first_node_b, counter);
    ft_lstiter(first_node_a,print_content);
    ft_lstclear(&first_node_a,free);
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