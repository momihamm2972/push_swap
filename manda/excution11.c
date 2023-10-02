/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution11.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 06:55:48 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/02 07:15:21 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*at_least_of_to(t_node **stack)
{
	t_node	*ptr;
	t_node	*less;
	int		min;

	ptr = (*stack);
	if (!ptr)
		return (NULL);
	min = ptr->total_moves;
	less = ptr;
	while (ptr)
	{
		if (min > ptr->total_moves)
		{
			min = ptr->total_moves;
			less = ptr;
		}
		ptr = ptr->next;
	}
	return (less);
}

void	p_move(t_parss *meekz, t_node *boss)
{
	while (boss->moves_a > 0 && boss->moves_b > 0)
	{
		rr(meekz->stack_a, meekz->stack_b);
		boss->moves_a--;
		boss->moves_b--;
	}
	while (boss->moves_a > 0)
	{
		rotate(meekz->stack_a, 0);
		boss->moves_a--;
	}
	while (boss->moves_b > 0)
	{
		rotate(meekz->stack_b, 1);
		boss->moves_b--;
	}
	push_to_stack(meekz->stack_b, meekz->stack_a, 1);
}

t_node	*second_node(t_node **stack, int info)
{
	t_node	*ptr;

	ptr = (*stack);
	while (ptr)
	{
		if (ptr->data > info)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

t_node	*at_least(t_node **stack)
{
	t_node	*ptr;
	t_node	*less;
	int		min;

	ptr = (*stack);
	if (!ptr)
		return (NULL);
	min = ptr->moves_b;
	while (ptr)
	{
		if (min > ptr->moves_b)
		{
			min = ptr->moves_b;
			less = ptr;
		}
		ptr = ptr->next;
	}
	return (less);
}

t_node	*min_instractions(t_node **stack)
{
	t_node	*ptr;
	t_node	*node;
	int		min;

	ptr = (*stack);
	if (!ptr)
		return (NULL);
	node = ptr;
	min = ptr->total_moves;
	while (ptr)
	{
		if (min > ptr->total_moves)
		{
			min = ptr->total_moves;
			node = ptr;
		}
		ptr = ptr->next;
	}
	return (node);
}
