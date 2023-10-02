/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:31 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/02 07:06:15 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moves_befor(t_node **stack)
{
	t_node	*ptr;

	ptr = (*stack);
	while (ptr)
	{
		if (ptr->are_in == 1)
		{
			if (ptr->indx_of_node <= ft_lstsize((*stack)) / 2)
			{
				ptr->moves_b = ptr->indx_of_node;
				ptr->total_moves = ptr->moves_b;
			}
			else if (ptr->indx_of_node > ft_lstsize((*stack)) / 2)
			{
				ptr->moves_b = ft_lstsize((*stack)) - ptr->indx_of_node;
				ptr->moves_b *= -1;
				ptr->total_moves = ptr->moves_b;
				ptr->total_moves *= -1;
			}
		}
		ptr = ptr->next;
	}
}

t_node	*first_go(t_node **stack)
{
	t_node	*ptr;

	ptr = (*stack);
	while (ptr)
	{
		if (ptr->are_in == 1)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

t_node	*next_to_go(t_node **stack)
{
	t_node	*ptr;
	t_node	*node;
	int		min;

	ptr = (*stack);
	node = first_go(stack);
	min = node->total_moves;
	while (ptr)
	{
		if (ptr->are_in == 1)
		{
			if (min > ptr->total_moves)
			{
				min = ptr->total_moves;
				node = ptr;
			}
		}
		ptr = ptr->next;
	}
	return (node);
}

int	stil_ther(t_node **kmya)
{
	t_node	*ptr;

	ptr = (*kmya);
	while (ptr)
	{
		if (ptr->are_in == 1)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

void	make_the_lis_in_a(t_parss *fcbayern)
{
	t_node	*go;

	fcbayern->stack_b = malloc(sizeof(t_node *));
	(*fcbayern->stack_b) = NULL;
	indxy_stack(fcbayern->stack_a);
	while (1)
	{
		if (stil_ther (fcbayern->stack_a) == 0)
			break ;
		moves_befor(fcbayern->stack_a);
		go = next_to_go(fcbayern->stack_a);
		make_money_a(fcbayern->stack_a, go, go->data);
		push_to_stack(fcbayern->stack_a, fcbayern->stack_b, 0);
	}
	make_a_in_oredre (fcbayern->stack_a);
}
