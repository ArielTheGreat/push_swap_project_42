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

int	check_order_min_to_max(t_node *first_node)
{
	t_node	*second_node;

	second_node = first_node->next;
	while (second_node != NULL
		&& second_node->value
		> first_node->value)
	{
		first_node = first_node->next;
		second_node = second_node->next;
	}
	if (second_node != NULL)
		return (0);
	return (1);
}

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

int	ft_check_not_digit_character(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != '+' && str[i] != '-')
			return (1);
		i++;
	}
	return (0);
}

int	check_validity(char **elements, int *counter_arguments)
{
	int	i;

	i = 0;
	while (elements[i] != NULL)
	{
		if (ft_check_not_digit_character(elements[i]) == 1
			|| ft_check_is_int(elements[i]) == 0)
			return (1);
		(*counter_arguments)++;
		i++;
	}
	return (0);
}
