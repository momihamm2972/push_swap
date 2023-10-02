/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution7.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 21:17:49 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/02 07:06:37 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	n_move(t_parss *dave, t_node *boss)
{
	while (boss->moves_a < 0 && boss->moves_b < 0)
	{
		rrr(dave->stack_a, dave->stack_b);
		boss->moves_a++;
		boss->moves_b++;
	}
	while (boss->moves_a < 0)
	{
		rev_rotate(dave->stack_a, 0);
		boss->moves_a++;
	}
	while (boss->moves_b < 0)
	{
		rev_rotate(dave->stack_b, 1);
		boss->moves_b++;
	}
	push_to_stack(dave->stack_b, dave->stack_a, 1);
}

void	porn(t_parss *cee, t_node *boss)
{
	while (boss->moves_a > 0)
	{
		rotate(cee->stack_a, 0);
		boss->moves_a--;
	}
	while (boss->moves_a < 0)
	{
		rev_rotate(cee->stack_a, 0);
		boss->moves_a++;
	}
	while (boss->moves_b > 0)
	{
		rotate(cee->stack_b, 1);
		boss->moves_b--;
	}
	while (boss->moves_b < 0)
	{
		rev_rotate(cee->stack_b, 1);
		boss->moves_b++;
	}
	push_to_stack(cee->stack_b, cee->stack_a, 1);
}

void	a_stro(t_parss *drake, t_node *boss)
{
	while (boss->moves_b != 0)
	{
		if (boss->moves_b > 0)
		{
			rotate (drake->stack_b, 1);
			boss->moves_b--;
		}
		else if (boss->moves_b < 0)
		{
			rev_rotate (drake->stack_b, 1);
			boss->moves_b++;
		}
	}
	push_to_stack(drake->stack_b, drake->stack_a, 1);
}

void	b_stro(t_parss *pnl, t_node *boss)
{
	while (boss->moves_a != 0)
	{
		if (boss->moves_a > 0)
		{
			rotate (pnl->stack_a, 0);
			boss->moves_a--;
		}
		else if (boss->moves_a < 0)
		{
			rev_rotate (pnl->stack_a, 0);
			boss->moves_a++;
		}
	}
	push_to_stack(pnl->stack_b, pnl->stack_a, 1);
}

void	what_is_it(t_parss *gang, t_node *boss)
{
	if (boss->moves_a > 0 && boss->moves_b > 0)
		p_move(gang, boss);
	else if (boss->moves_a < 0 && boss->moves_b < 0)
		n_move(gang, boss);
	else if ((boss->moves_a > 0 && boss->moves_b < 0)
		|| (boss->moves_a < 0 && boss->moves_b > 0))
		porn(gang, boss);
	else if (boss->moves_a == 0 && boss->moves_b != 0)
		a_stro (gang, boss);
	else if (boss->moves_b == 0 && boss->moves_a != 0)
		b_stro (gang, boss);
	else if (boss->moves_a == 0 && boss->moves_b == 0)
		push_to_stack (gang->stack_b, gang->stack_a, 1);
}
