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

int	*process_arguments(int argc, char *argv[])
{
    int	*array_int;
    int	counter;
    int	counter_for_array;

    array_int = malloc((argc - 1) * sizeof(int));
    if (!array_int)
        return (NULL);
    counter = 1;
    counter_for_array = 0;
    while (counter < argc)
        array_int[counter_for_array++] = ft_atoi(argv[counter++]);
    order_array_quicksort(array_int, argc - 1);
    return (array_int);
}

t_list	*create_and_link_nodes(int *array_int, int argc, char **argv)
{
    t_list	*first_node;
    t_list	*last_node;
    t_list	*new_node;
    int		counter;

    first_node = NULL;
    last_node = NULL;
    counter = 1;
    while (counter < argc)
    {
        new_node = create_node(search_in_array(array_int, argv[counter]));
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

int	main(int argc, char *argv[])
{
    int		*array_int;
    t_list	*first_node;

    if (argc < 2)
        return (0);
    array_int = process_arguments(argc, argv);
    if (!array_int)
        return (1);
    first_node = create_and_link_nodes(array_int, argc, argv);
    if (!first_node)
    {
        free(array_int);
        return (1);
    }
    do_things(first_node, argc - 1);
    free(array_int);
    return (0);
}
