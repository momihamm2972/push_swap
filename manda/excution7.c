/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution7.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 21:17:49 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/30 09:21:44 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *at_least_of_to(t_node **stack)
{
	t_node *ptr;
	t_node *less;
	int min;

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

void p_move(t_parss *meekz, t_node *boss)
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

void n_move(t_parss *dave, t_node *boss)
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

void porn(t_parss *cee, t_node *boss)
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

void	a_stro (t_parss *drake, t_node *boss)
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
}

void	b_stro (t_parss *pnl, t_node *boss)
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
}

void what_is_it(t_parss *gang, t_node *boss)
{
	printf ("weselt\n");
	if (boss->moves_a > 0 && boss->moves_b > 0)
	{
		p_move(gang, boss);
		printf ("italia\n");
	}
	else if (boss->moves_a < 0 && boss->moves_b < 0)
	{
		n_move(gang, boss);
		printf ("zetla\n");
	}
	else if ((boss->moves_a > 0 && boss->moves_b < 0) || (boss->moves_a < 0 && boss->moves_b > 0))
	{
		porn(gang, boss);
		printf ("albizi\n");
	}
	else if (boss->moves_a == 0 && boss->moves_b != 0)
	{
		a_stro (gang, boss);
		printf ("madafack\n");
	}
	else if (boss->moves_b == 0 && boss->moves_a != 0)
	{
		b_stro (gang, boss);
		printf ("lean\n");
	}
}
