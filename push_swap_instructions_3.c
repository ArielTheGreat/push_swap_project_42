/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions_3.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:14:39 by frocha            #+#    #+#             */
/*   Updated: 2024/11/21 16:14:42 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	rrr(t_list **first_node_a, t_list **first_node_b)
{
	rra(first_node_a);
	rrb(first_node_b);
	write(1,"RRR\n",4);
}

void	print_content(void *content)
{
	printf("%d ", *(int *)content);
}
