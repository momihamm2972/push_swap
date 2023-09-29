/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:46:44 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/29 03:19:25 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (delta == 0)
		write (1, "pb\n", 3);
	else if (delta == 1)
		write (1, "pa\n", 3);
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
	if (delta == 0)
		write (1, "ra\n", 3);
	else if (delta == 1)
		write (1, "rb\n", 3);
	indxy_stack (stack);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate (stack_a, 2);
	rotate (stack_b, 2);
	write (1, "rr\n", 3);
}

// int main ()
// {
// 	t_node **a;
// 	t_node **b;

// 	a = malloc (sizeof (t_node *));
// 	b = malloc (sizeof (t_node *));
// 	(*a) = ft_lstnew (91);
// 	// (*b) = ft_lstnew (22);
// 	// printf ("a %d\tb %d\n",(*a)->data,(*b)->data);
// 	push_to_stack (a,b,0);
// 	printf ("%d\t\n",(*b)->data);
// 	ft_free_a_stack (a);
// 	ft_free_a_stack (b);
// }
