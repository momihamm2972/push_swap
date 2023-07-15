/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:46:44 by momihamm          #+#    #+#             */
/*   Updated: 2023/07/13 01:50:56 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_2_elements(t_node **stack, int delta)
{
	int swaper;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return;
	swaper = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data =	swaper;
	swaper = (*stack)->position;
	(*stack)->position = (*stack)->next->position;
	(*stack)->next->position =	swaper;
	if (delta == 0)
		write (1, "sa\n", 3);
	else if (delta == 1)
		write (1, "sb\n", 3);
}


void	ss(t_node **stack_a, t_node **stack_b)
{
	swap_2_elements(stack_a, 2);
	swap_2_elements(stack_b, 2);
	write (1, "ss\n", 3);
}

void	push_to_stack(t_node **stack_0, t_node **stack_1, int delta)
{
	// t_node *tmp;
	t_node *fri;
	
	if (!(*stack_0))
		return ;
	ft_lstadd_front(stack_1, ft_lstnew((*stack_0)->data));
	(*stack_1)->position = (*stack_0)->position;
	fri = (*stack_0);
	(*stack_0) = (*stack_0)->next;
	free (fri);
	if (delta == 0)
		write (1, "pa\n", 3);
	else
		write (1, "pb\n", 3);
}

void	rotate (t_node **stack, int delta)
{
	// t_node *tmp;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
	t_node *last;
	
	if (!(*stack))
		return ;
	// tmp = (*stack);
	last = ft_lstlast ((*stack));
	last->next = (*stack);
	(*stack) = (*stack)->next;
	last->next->next = NULL;
	if (delta == 0)
		write (1, "ra\n", 3);
	else if (delta == 1)
		write (1, "rb\n", 3);
}

void	rr (t_node **stack_a, t_node **stack_b)
{
	rotate (stack_a, 2);
	rotate (stack_b, 2);
	write (1, "rr\n", 3);
}



// int main ()
// {
// 	t_node *head = ft_lstnew (04);
// 	head->next = ft_lstnew (99);
// 	head->next->next = ft_lstnew (32);
// 	head->next->next->next = ft_lstnew (0);
// 	// swap_2_elements ;
// 	make_the_scnd_in_top ()
// 	print_nodes (&head);
// }
