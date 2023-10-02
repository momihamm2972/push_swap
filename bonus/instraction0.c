/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:20:22 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/01 19:18:49 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_2_elements(t_node **stack, int delta)
{
	int	swaper;

	(void) delta;
	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	swaper = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = swaper;
	swaper = (*stack)->indx_of_stack;
	(*stack)->indx_of_stack = (*stack)->next->indx_of_stack;
	(*stack)->next->indx_of_stack = swaper;
	// if (delta == 0)
	// 	write (1, "sa\n", 3);
	// else if (delta == 1)
	// 	write (1, "sb\n", 3);
	indxy_stack (stack);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap_2_elements(stack_a, 2);
	swap_2_elements(stack_b, 2);
	// write (1, "ss\n", 3);
}

void	push_to_stack(t_node **stack_0, t_node **stack_1, int delta)
{
	t_node	*tmp;

	(void) delta;
	if (!(*stack_0))
		return ;
	if (!stack_1 || !(*stack_1))
	{
		tmp = (*stack_0);
		(*stack_1) = tmp;
		(*stack_0) = (*stack_0)->next;
		(*stack_1)->next = NULL;
	}
	else
	{
		tmp = (*stack_1);
		(*stack_1) = (*stack_0);
		(*stack_0) = (*stack_0)->next;
		(*stack_1)->next = tmp;
	}
	// if (delta == 0)
	// 	write (1, "pb\n", 3);
	// else if (delta == 1)
	// 	write (1, "pa\n", 3);
	indxy_stack (stack_0);
	indxy_stack (stack_1);
}

void	rotate(t_node **stack, int delta)
{
	t_node	*last;

	(void)delta;
	if (!(*stack))
		return ;
	last = ft_lstlast (stack);
	last->next = (*stack);
	(*stack) = (*stack)->next;
	last->next->next = NULL;
	// if (delta == 0)
	// 	write (1, "ra\n", 3);
	// else if (delta == 1)
	// 	write (1, "rb\n", 3);
	indxy_stack (stack);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
    if (!(*stack_a) || (*stack_b))
        return ;
	rotate (stack_a, 2);
	rotate (stack_b, 2);
	// write (1, "rr\n", 3);
}