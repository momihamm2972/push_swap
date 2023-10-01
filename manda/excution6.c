/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:44 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/01 08:27:31 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_of_top(t_node **stack, int info, int nameinst, int type_of)
{
	if (type_of > 0)
	{
		while ((*stack)->data != info)
			rotate (stack, nameinst);
	}
	else if (type_of < 0)
	{
		while ((*stack)->data != info)
			rev_rotate (stack, nameinst);
	}
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

// int	big_than(t_node **stack, int info)
// {
// 	t_node	*ptr;
// 	int	big;

// 	ptr = (*stack);
// 	while (ptr)
// 	{
// 		if (ptr->data < big)
// 			// printf ("wiiiiiiiiiii  %d \n",big);
// 		if (ptr->data > info)
// 			big = ptr->data;
// 		ptr = ptr->next;
// 	}
// 	return (big);
// }

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
			one = ptr->data;
			if (ptr->data <= one)
			{
				one = ptr->data;
				node = ptr;
				if (is_it (stack, info, one) == 0)
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
