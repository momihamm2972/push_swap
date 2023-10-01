/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution9.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 21:18:03 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/01 08:09:00 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moveto(t_node **stack, t_node *min)
{
	t_node	*ptr;

	ptr = (*stack);
	indxy_stack (stack);
	if (!ptr || !min)
		return ;
	while (ptr)
	{
		if (ptr->data == min->data)
		{
			if (ptr->indx_of_node < ft_lstsize ((*stack)) / 2)
				ptr->moves_a = ptr->indx_of_node;
			else if (ptr->indx_of_node >= ft_lstsize ((*stack)) / 2)
			{
				ptr->moves_a = ft_lstsize ((*stack)) - ptr->indx_of_node;
				ptr->moves_a *= -1;
			}
		}
		ptr = ptr->next;
	}
}

void	top_for(t_node **stack, t_node *min)
{
	while (min->moves_a > 0)
	{
		rotate (stack, 0);
		min->moves_a--;
	}
	while (min->moves_a < 0)
	{
		rev_rotate (stack, 0);
		min->moves_a++;
	}
}

void	ft_for(t_parss *sherin)
{
	t_node	*min;

	(sherin->stack_b) = malloc (sizeof (t_node *));
	(*sherin->stack_b) = NULL;
	min = min_value_in (sherin->stack_a);
	moveto (sherin->stack_a, min);
	top_for (sherin->stack_a, min);
	push_to_stack (sherin->stack_a, sherin->stack_b, 0);
	ft_tree (sherin->stack_a);
	push_to_stack (sherin->stack_b, sherin->stack_a, 1);
}

void	ft_five_complet(t_parss *jamal)
{
	t_node	*min;

	jamal->stack_b = malloc (sizeof (t_node *));
	(*jamal->stack_b) = NULL;
	min = min_value_in (jamal->stack_a);
	moveto (jamal->stack_a, min);
	top_for (jamal->stack_a, min);
	push_to_stack (jamal->stack_a, jamal->stack_b, 0);
	min = min_value_in (jamal->stack_a);
	moveto (jamal->stack_a, min);
	top_for (jamal->stack_a, min);
	push_to_stack (jamal->stack_a, jamal->stack_b, 0);
	ft_tree (jamal->stack_a);
	push_to_stack (jamal->stack_b, jamal->stack_a, 1);
	push_to_stack (jamal->stack_b, jamal->stack_a, 1);
}
