/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:31 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/20 18:27:18 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_a_in_oredre(t_node **stack)
{
	while (1)
	{
		if ((*stack)->length == 1)
			return ;
		else
			rotate (stack, 0);
	}
}

int	check_if_lis_in_a(t_node **stack)
{
	t_node	*ptr;

	ptr = (*stack);
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
	t_node	**ptr;

	ptr = fcbayern->stack_a;
	fcbayern->stack_b = malloc (sizeof (t_node *));
	(*fcbayern->stack_b) = NULL;
	while (1)
	{
		if (check_if_lis_in_a (fcbayern->stack_a) == 0)
			break ;
		if ((*ptr)->are_in == 1)
			push_to_stack (fcbayern->stack_a, fcbayern->stack_b, 0);
		if ((*ptr)->are_in == 0)
			rotate (fcbayern->stack_a, 0);
	}
	make_a_in_oredre (fcbayern->stack_a);
	indxy_stack (fcbayern->stack_a);
	indxy_stack (fcbayern->stack_b);
}
// chi SEV bano 3end mo3ad;
// tap;
// 0 4 12 "      2      10       " "6"    9 13 3 11        "7      15"