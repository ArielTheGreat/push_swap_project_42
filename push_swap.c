/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:05:50 by frocha            #+#    #+#             */
/*   Updated: 2024/11/21 18:05:51 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void leaks()
{
	system("leaks push_swap");
}
int	main(int argc, char *argv[])
{
	int		*array_int;
	t_list	*first_node;

	if (argc < 2)
		return (0);
	array_int = process_arguments(argc, argv);
	if (!array_int)
	{
		printf("Invalid argument");
		return (1);
	}
	first_node = create_and_link_nodes(array_int, argc, argv);
	if (!first_node)
	{
		free(array_int);
		return (1);
	}
	free(array_int);
	do_things(first_node, argc - 1);
	atexit(leaks);
	return (0);
}
