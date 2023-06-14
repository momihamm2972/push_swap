/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:46:44 by momihamm          #+#    #+#             */
/*   Updated: 2023/06/13 04:10:02 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_2_elements(t_node *stack)
{
	int swaper;

	if (stack == NULL || stack->next == NULL)
		return;
	swaper = stack->data;
	stack->data = stack->next->data;
	stack->next->data =	swaper;
}

void	push_to_stack(t_node *stack_0, t_node **stack_1)
{
	t_node *tmp;
	
	if (!stack_0)
	{
		printf ("kmi o tkma o 3ref ach kayen tma\n");
		return ;
	}
	ft_lstadd_front(stack_1, ft_lstnew(stack_0->data));
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap_2_elements(*stack_a);
	swap_2_elements(*stack_b);
}

void	rotate (t_node **stack)
{
	t_node *tmp;
	t_node *last;
	
	if (!(*stack))
		return ;
	tmp = (*stack);
	last = ft_lstlast ((*stack));
	last->next = (*stack);
	(*stack) = (*stack)->next;
	last->next->next = NULL;
}

void	rr (t_node **stack_a, t_node **stack_b)
{
	rotate (stack_a);
	rotate (stack_b);
}


void rev_rotate (t_node **stack)
{
	t_node *the_last;
	t_node *new_last;
	
	if (!(*stack))
		return ;
	the_last = ft_lstlast ((*stack));
	new_last = before_the_last(stack);
	the_last->next = (*stack);
	(*stack) = new_last->next;
	new_last->next = NULL;
}

void	rrr (t_node **stack_a, t_node **stack_b)
{
	rev_rotate (stack_a);
	rev_rotate (stack_b);
}
