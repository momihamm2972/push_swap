/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:37 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/02 07:06:25 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	big_to_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	posi_val(int val_a, int val_b)
{
	int	a;
	int	b;

	a = val_a;
	b = val_b;
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	return (a + b);
}

void	total_of_moves(t_parss *tamawayet)
{
	t_node	*ptr;

	ptr = (*tamawayet->stack_b);
	while (ptr)
	{
		if (ptr->moves_a == ptr->moves_b)
		{
			ptr->total_moves = ptr->moves_a;
			if (ptr->total_moves < 0)
				ptr->total_moves *= -1;
		}
		else if (ptr->moves_a >= 0 && ptr->moves_b >= 0)
			ptr->total_moves = big_to_int (ptr->moves_a, ptr->moves_b);
		else if (ptr->moves_a < 0 && ptr->moves_b < 0)
			ptr->total_moves
				= big_to_int (ptr->moves_a * -1, ptr->moves_b * -1);
		else
			ptr->total_moves = posi_val (ptr->moves_a, ptr->moves_b);
		ptr = ptr->next;
	}
}

void	an_node(t_node **stack, int info)
{
	t_node	*ptr;

	ptr = (*stack);
	while (ptr)
	{
		if (ptr->data == info)
		{
			if (ptr->indx_of_node <= (ft_lstsize ((*stack)) / 2))
			{
				ptr->moves_b = ptr->indx_of_node;
			}
			else if (ptr->indx_of_node > (ft_lstsize ((*stack)) / 2))
			{
				ptr->moves_b = ft_lstsize ((*stack)) - ptr->indx_of_node;
				ptr->moves_b *= -1;
			}
		}
		ptr = ptr->next;
	}
}

void	make_it_top(t_parss *munchen, int info)
{
	t_node	*ptr;

	ptr = (*munchen->stack_b);
	while (ptr)
	{
		if (ptr->data == info)
		{
			if (ptr->moves_b > 0)
			{
				while ((*munchen->stack_b)->data != info)
					rotate (munchen->stack_b, 1);
			}
			else if (ptr->moves_b < 0)
			{
				while ((*munchen->stack_b)->data != info)
					rev_rotate (munchen->stack_b, 1);
			}
		}
		ptr = ptr->next;
	}
}
