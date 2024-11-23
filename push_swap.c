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

int	ft_check_is_int(const char *str)
{
	int		sign;
	long	result;
	int		i;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > (LONG_MAX - (str[i] - '0')) / 10)
			return (0);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result *= sign;
	if (result > INT_MAX || result < INT_MIN)
		return (0);
	return (1);
}

t_list	*create_and_link_nodes(int *array_int, int argc, char **argv)
{
	t_list	*first_node;
	t_list	*last_node;
	int		counter;

	first_node = NULL;
	last_node = NULL;
	counter = 1;
	while (counter < argc)
	{
		if (!append_and_check(&first_node, &last_node,
				array_int, argv[counter]))
		{
			ft_lstclear(&first_node, free);
			if (array_int && *array_int)
				free(array_int);
			return (NULL);
		}
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
	{
		write(1, "Error\n", 6);
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
	return (0);
}
