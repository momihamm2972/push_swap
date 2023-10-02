/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution10.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 06:55:32 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/02 07:15:08 by momihamm         ###   ########.fr       */
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
					_b->moves_a
						= (ft_lstsize(*j->stack_a) - _a->indx_of_node) * -1;
			}
			_a = _a->next;
		}
		_b = _b->next;
	}
}

void	make_a_in_oredre(t_node **stack)
{
	t_node	*ptr;

	ptr = (*stack);
	while (ptr)
	{
		if (ptr->length == 1)
		{
			if (ptr->indx_of_node <= ft_lstsize ((*stack)) / 2)
				ptr->moves_a = ptr->indx_of_node;
			else if (ptr->indx_of_node > ft_lstsize ((*stack)) / 2)
				ptr->moves_a = (ft_lstsize ((*stack)) - ptr->indx_of_node) * -1;
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
