/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:31 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/29 22:09:50 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void make_a_in_oredre(t_node **stack)
{
	t_node *ptr;

	ptr = (*stack);
	while (ptr)
	{
		if (ptr->length == 1)
		{
			if (ptr->indx_of_node <= ft_lstsize ((*stack)) / 2)
				ptr->moves_a = ptr->indx_of_node;
			else if (ptr->indx_of_node > ft_lstsize ((*stack)) / 2)
			{
				ptr->moves_a = ft_lstsize ((*stack)) - ptr->indx_of_node;
				ptr->moves_a *= -1;
			}
			if (ptr->moves_a > 0)
			{
				while ((*stack)->moves_a != ptr->moves_a)
					rotate (stack, 0);
			}
			else if (ptr->moves_b < 0)
			{
				while ((*stack)->moves_a != ptr->moves_a)
					rev_rotate (stack, 0);
			}
		}
		ptr = ptr->next;
	}
}

int check_if_lis_in_a(t_node **stack)
{
	t_node *ptr;

	ptr = (*stack);
	while (ptr)
	{
		if (ptr->are_in == 1)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}
void moves_befor(t_node **stack)
{
	t_node *ptr;

	ptr = (*stack);
	while (ptr)
	{
		if (ptr->are_in == 1)
		{
			if (ptr->indx_of_node <= ft_lstsize((*stack)) / 2)
			{
				ptr->moves_b = ptr->indx_of_node;
				ptr->total_moves = ptr->moves_b + 1;
			}
			else if (ptr->indx_of_node > ft_lstsize((*stack)) / 2)
			{
				ptr->moves_b = ft_lstsize((*stack)) - ptr->indx_of_node;
				ptr->moves_b *= -1;
				ptr->total_moves = ptr->moves_b;
				ptr->total_moves *= -1;
				ptr->total_moves += 1;
			}
		}
		ptr = ptr->next;
	}
}

t_node *first_go(t_node **stack)
{
	t_node *ptr;

	ptr = (*stack);
	while (ptr)
	{
		if (ptr->are_in == 1)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

t_node *next_to_go(t_node **stack)
{
	t_node *ptr;
	t_node *node;
	int min;

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

int	stil_ther (t_node **kmya)
{
	t_node *ptr;

	ptr = (*kmya);
	while (ptr)
	{
		if (ptr->are_in == 1)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

void make_the_lis_in_a(t_parss *fcbayern)
{
	// t_node	**ptr;
	t_node *go;

	// ptr = fcbayern->stack_a;
	fcbayern->stack_b = malloc(sizeof(t_node *));
	(*fcbayern->stack_b) = NULL;
	indxy_stack(fcbayern->stack_a);
	while (1)
	{
		if (stil_ther (fcbayern->stack_a) == 0)
			break;
		moves_befor(fcbayern->stack_a);
		go = next_to_go(fcbayern->stack_a);
		// printf("awera %d\n", go->data);
		make_money_a(fcbayern->stack_a, go, go->data);
		push_to_stack(fcbayern->stack_a, fcbayern->stack_b, 0);
	}

	// moves_befor(fcbayern->stack_a);
	// go = next_to_go(fcbayern->stack_a);
	// printf ("awera %d\n", go->data);
	// make_money_a(fcbayern->stack_a, go, go->data);
	// push_to_stack(fcbayern->stack_a, fcbayern->stack_b, 0);

	make_a_in_oredre (fcbayern->stack_a);
	// print_nodes(fcbayern->stack_a);
	// printf("$$$$$$$$$$$$$$$$$$$$\n");
	// print_nodes(fcbayern->stack_b);
}
// chi SEV bano 3end mo3ad;
// tap;
// 0 4 12 "      2      10       " "6"    9 13 3 11        "7      15"