/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:44 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/02 07:08:48 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*next_of_num(t_node **stack, int info)
{
	t_node	*ptr;
	t_node	*node;

	ptr = (*stack);
	node = ptr;
	while (ptr)
	{
		if (ptr->data > info)
			node = ptr;
		ptr = ptr->next;
	}
	return (node);
}

int	is_it(t_node **stack, int info, int min)
{
	t_node	*ptr;

	ptr = (*stack);
	while (ptr)
	{
		if (ptr->data > info && ptr->data < min)
			return (-1);
		ptr = ptr->next;
	}
	return (0);
}

t_node	*next_of_num_sicondo(t_node **stack, int info)
{
	t_node	*ptr;
	t_node	*node;
	int		one;

	ptr = (*stack);
	one = ptr->data;
	while (ptr)
	{
		if (ptr->data > info)
		{
			if (ptr->data <= one)
			{
				node = ptr;
				if (is_it (stack, info, ptr->data) == 0)
					break ;
			}
			else if (ptr->next == NULL && ptr->data > one)
			{
				one = ptr->data;
				node = ptr;
			}
		}
		ptr = ptr->next;
	}
	return (node);
}

void	make_money_a(t_node **stack, t_node *place, int info)
{
	if (!(*stack))
		return ;
	if (place->moves_b < 0)
	{
		while ((*stack)->data != info)
			rev_rotate (stack, 0);
	}
	else if (place->moves_b > 0)
	{
		while ((*stack)->data != info)
			rotate (stack, 0);
	}
}

void	make_money_b(t_node **stack, t_node *place, int info)
{
	if (!(*stack))
		return ;
	if (place->moves_b < 0)
	{
		while ((*stack)->data != info)
			rev_rotate (stack, 1);
	}
	else if (place->moves_b > 0)
	{
		while ((*stack)->data != info)
			rotate (stack, 1);
	}
}
