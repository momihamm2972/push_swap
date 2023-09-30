/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:41 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/30 10:45:50 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void if_min_max_in_b(t_parss *azalim)
{
	if (min_value(azalim->stack_b) < min_value(azalim->stack_a))
	{
		// indxy_stack(azalim->stack_a);
		// indxy_stack(azalim->stack_b);
		an_node(azalim->stack_b, min_value(azalim->stack_b));
		make_it_top(azalim, min_value(azalim->stack_b));
		push_to_stack(azalim->stack_b, azalim->stack_a, 1);
	}
	if (big_value(azalim->stack_b) > big_value(azalim->stack_a))
	{
		// indxy_stack (azalim->stack_a);
		// indxy_stack (azalim->stack_b);
		an_node(azalim->stack_b, big_value(azalim->stack_b));
		make_it_top(azalim, big_value(azalim->stack_b));
		push_to_stack(azalim->stack_b, azalim->stack_a, 1);
		// return ;
		rotate(azalim->stack_a, 0);
	}
}

void rev_or(t_node **stack)
{
	t_node *ptr;

	ptr = (*stack);
	while (ptr)
	{
		if (ptr->indx_of_node < (ft_lstsize((*stack)) / 2))
			ptr->moves_b = ptr->indx_of_node;
		else if (ptr->indx_of_node >= (ft_lstsize((*stack)) / 2))
		{
			ptr->moves_b = ft_lstsize((*stack)) - ptr->indx_of_node;
			ptr->moves_b *= -1;
		}
		ptr = ptr->next;
	}
}

int how_may_move(t_parss *kane, int info)
{
	t_node *ptr;
	int cont = 0;

	ptr = (*kane->stack_a);
	while (ptr)
	{
		if (ptr->data > info)
		{
			if (ptr->moves_b >= 0)
			{
				cont = ptr->moves_b;
				// printf ("l3alamyaaaaaaaaaaaaaaaaaaaa  %d                  **\n",cont);
			}
			else if (ptr->moves_b < 0)
			{
				cont = ptr->moves_b * (-1);
				// printf ("kmi %d                                 **\n",cont);
			}
			// printf ("!!!!!!!!!!!!!!!!!!!!!!!!!!  %d  !!!!!!!!!!!!!!!!!!!!!\n",cont);
			return (cont);
		}
		ptr = ptr->next;
	}
	return (0);
}

void keep_it(t_parss *speed)
{
	// indxy_stack (speed->stack_a);
	// indxy_stack (speed->stack_b);
	// if_min_max_in_b (speed);
	best_move_in_b(speed);
	best_move_in_a(speed);
	total_of_moves(speed);
	// rev_or (speed->stack_a);
}

void ft_all_most(t_parss *sane)
{
	t_node *small;
	int i = 0;
	while (1)
	{
		// if (sane->stack_b == NULL)
		// 	break;
		keep_it(sane);
		i++;
		if (i >= 3)
			break;
		small = at_least_of_to(sane->stack_b);
		// printf("%d a%d b%d t%d\n", small->data, small->moves_a, small->moves_b, small->total_moves);
		what_is_it(sane, small);
	}
}
