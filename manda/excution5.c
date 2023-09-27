/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:41 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/26 20:47:16 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_min_max_in_b (t_parss *azalim)
{
	if (min_value (azalim->stack_b) < min_value (azalim->stack_a))
	{
		an_node (azalim->stack_b, min_value (azalim->stack_b));
		make_it_top (azalim, min_value (azalim->stack_b));
		push_to_stack (azalim->stack_b, azalim->stack_a, 1);
	}
	if (big_value (azalim->stack_b) > big_value (azalim->stack_a))
	{
		an_node (azalim->stack_b, big_value (azalim->stack_b));
		make_it_top (azalim,big_value (azalim->stack_b));
		push_to_stack (azalim->stack_b, azalim->stack_a, 1);
		rotate (azalim->stack_a, 0);
	}         
}

void	rev_or (t_node **stack)
{
	t_node	*ptr;

	ptr = (*stack);
	while (ptr)
	{
		if (ptr->indx_of_node < (ft_lstsize ((*stack)) / 2))
			ptr->moves_b = ptr->indx_of_node;
		else if (ptr->indx_of_node >= (ft_lstsize ((*stack)) / 2))
		{
			ptr->moves_b = ft_lstsize ((*stack)) - ptr->indx_of_node;
			ptr->moves_b *= -1;
		}
		ptr = ptr->next;
	}
}

int	how_may_move (t_parss *kane, int info)
{
	t_node	*ptr;
	int		cont;

	ptr = (*kane->stack_a);
	while (ptr)
	{
		if (ptr->data > info)
		{
			if (ptr->moves_b < 0)
				cont = ptr->moves_b * (-1);
			else if (ptr->moves_b > 0)
				cont = ptr->moves_b;
			return (cont);
		}
		ptr = ptr->next;
	}
	return (0);
}

void	keep_it (t_parss *speed)
{
	best_move_in_b (speed);
	best_move_in_a (speed);
	total_of_a_b (speed);
	rev_or (speed->stack_a);
}

void    ft_all_most (t_parss *sane)
{
    t_node  *ptr_a;
	// t_node	*less;
    // t_node  *ptr_b;

    ptr_a = (*sane->stack_a);
    // ptr_b = (*sane->stack_b);
	while (ptr_a)
	{
		keep_it (sane);
		// less = at_least (sane->stack_b);
		// if ("")
		// printf ("               %d          %d          \n",less->data,less->moves_b);
		break;
		ptr_a = ptr_a->next;
		// ptr_b = ptr_b->next;
	}
}
