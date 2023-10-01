/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:37 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/01 07:00:57 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_move_in_b(t_parss *djaja)
{
	t_node	*ptr;

	ptr = (*djaja->stack_b);
	while (ptr)
	{
		if (ptr->indx_of_node <= (ft_lstsize ((*djaja->stack_b)) / 2))
		{
			ptr->moves_b = ptr->indx_of_node;
		}
		else if (ptr->indx_of_node > (ft_lstsize ((*djaja->stack_b)) / 2))
		{
			ptr->moves_b = ft_lstsize ((*djaja->stack_b)) - ptr->indx_of_node;
			ptr->moves_b *= -1;
		}
		ptr = ptr->next;
	}
}

void	best_move_in_a(t_parss *j)
{
	t_node	*_a;
	t_node	*_b;
	int		check;

	_b = (*j->stack_b);
	while (_b)
	{
		_a = (*j->stack_a);
		check = _b->data;
		while (_a)
		{
			if (_a->data > _b->data && (check == _b->data || _a->data < check))
			{
				check = _a->data;
				if (_a->indx_of_node <= (ft_lstsize((*j->stack_a)) / 2))
					_b->moves_a = _a->indx_of_node;
				else if (_a->indx_of_node > (ft_lstsize((*j->stack_a)) / 2))
				{
					_b->moves_a = (ft_lstsize(*j->stack_a) - _a->indx_of_node);
					_b->moves_a *= -1;
				}
			}
			_a = _a->next;
		}
		_b = _b->next;
	}
}

int	big_to_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	total_of_moves(t_parss *tamawayet)
{
	t_node	*ptr;
	int		p_val_a;
	int		p_val_b;

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
			ptr->total_moves = big_to_int (ptr->moves_a * -1, ptr->moves_b * -1);
		else
		{
			p_val_a = ptr->moves_a;
			p_val_b = ptr->moves_b;
			if (p_val_a < 0)
				p_val_a *= -1;
			if (p_val_b < 0)
				p_val_b *= -1;
			ptr->total_moves = p_val_a + p_val_b;
		}
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
