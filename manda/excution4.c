/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:37 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/28 04:07:46 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_move_in_b (t_parss *djaja)
{
	t_node	*ptr;

	ptr = (*djaja->stack_b);
	while (ptr)
	{
		if (ptr->indx_of_node < (ft_lstsize ((*djaja->stack_b)) / 2))
		{
			ptr->moves_b = ptr->indx_of_node;
		}
		else if (ptr->indx_of_node >= (ft_lstsize ((*djaja->stack_b)) / 2))
		{
			ptr->moves_b = ft_lstsize ((*djaja->stack_b)) - ptr->indx_of_node;
			ptr->moves_b *= -1;
		}
		ptr = ptr->next;
	}
}

void	best_move_in_a (t_parss *jwan)
{
	t_node	*ptr_a;
	t_node	*ptr_b;

	ptr_b = (*jwan->stack_b);
	while (ptr_b)
	{
		ptr_a = (*jwan->stack_a);
		while (ptr_a)
		{
			if (ptr_b->data < ptr_a->data)
			{
				if (ptr_a->indx_of_node <= (ft_lstsize ((*jwan->stack_a)) / 2))
					ptr_b->moves_a = ptr_a->indx_of_node;
				else if (ptr_a->indx_of_node >= (ft_lstsize ((*jwan->stack_a)) / 2))
				{
					ptr_b->moves_a = ft_lstsize ((*jwan->stack_a)) - ptr_a->indx_of_node;
					ptr_b->moves_a *= -1;
				}
				break;
			}
			ptr_a = ptr_a->next;
		}
		ptr_b = ptr_b->next;
	}
}

void	total_of_a_b (t_parss *tamawayet)
{
	t_node	*ptr;
	int		p_val_a;
	int		p_val_b;

	ptr = (*tamawayet->stack_b);
	while (ptr)
	{
		if (ptr->moves_b < 0 || ptr->moves_a < 0)
		{
			p_val_a = ptr->moves_a;
			p_val_b = ptr->moves_b;
			if (ptr->moves_a < 0)
				p_val_a = ptr->moves_a * (-1);
			if (ptr->moves_b < 0)
				p_val_b = ptr->moves_b * (-1);
			ptr->total_moves = p_val_a + p_val_b + 1;
		}
		else
			ptr->total_moves = ptr->moves_a + ptr->moves_b + 1;
		ptr = ptr->next;
	}
}

void	an_node (t_node **stack, int info)
{
	t_node	*ptr;

	ptr = (*stack);
	while (ptr)
	{
		if (ptr->data == info)
		{
			if (ptr->indx_of_node < (ft_lstsize ((*stack)) / 2))
			{
				ptr->moves_b = ptr->indx_of_node;
			}
			else if (ptr->indx_of_node >= (ft_lstsize ((*stack)) / 2))
			{
				ptr->moves_b = ft_lstsize ((*stack)) - ptr->indx_of_node;
				ptr->moves_b *= -1;
			}
		}
		ptr = ptr->next;
	}
}

void	make_it_top (t_parss *munchen, int info)
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
				// print_nodes (munchen->stack_b);
				// rev_rotate (munchen->stack_b, 1);
				// printf ("$$$$$$$$$$\n");
				// print_nodes (munchen->stack_b);
				// exit (0);
				while ((*munchen->stack_b)->data != info)
					rev_rotate (munchen->stack_b, 1);
			}
		}
		ptr = ptr->next;
	}
}