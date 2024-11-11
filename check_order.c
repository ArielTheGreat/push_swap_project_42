/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:38:00 by frocha            #+#    #+#             */
/*   Updated: 2024/11/11 23:38:01 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

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
