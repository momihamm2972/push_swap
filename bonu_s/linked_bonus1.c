/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_bonus1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:19:39 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/02 20:37:23 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"

void	swap_2_elements(t_node **stack)
{
	int	swaper;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	swaper = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = swaper;
	swaper = (*stack)->indx_of_stack;
	(*stack)->indx_of_stack = (*stack)->next->indx_of_stack;
	(*stack)->next->indx_of_stack = swaper;
	indxy_stack (stack);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap_2_elements(stack_a);
	swap_2_elements(stack_b);
}

void	push_to_stack(t_node **stack_0, t_node **stack_1)
{
	t_node	*tmp;

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
	indxy_stack (stack_0);
	indxy_stack (stack_1);
}

void	rotate(t_node **stack)
{
	t_node	*last;

	if (!(*stack))
		return ;
	last = ft_lstlast (stack);
	last->next = (*stack);
	(*stack) = (*stack)->next;
	last->next->next = NULL;
	indxy_stack (stack);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate (stack_a);
	rotate (stack_b);
}
