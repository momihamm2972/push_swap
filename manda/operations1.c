/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 00:38:47 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/30 12:06:28 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_node **stack, int delta)
{
	t_node	*the_last;
	t_node	*new_last;

	(void)delta;
	if (!(*stack))
		return ;
	the_last = ft_lstlast (stack);
	new_last = before_the_last(stack);
	the_last->next = (*stack);
	(*stack) = new_last->next;
	new_last->next = NULL;
	if (delta == 0)
		write (1, "rra\n", 4);
	else if (delta == 1)
		write (1, "rrb\n", 4);
	indxy_stack (stack);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rev_rotate (stack_a, 2);
	rev_rotate (stack_b, 2);
	write (1, "rrr\n", 4);
}

// int main ()
// {
// 	t_node **stack= malloc (sizeof (t_node *));
// 	(*stack) = ft_lstnew (1982);
// 	(*stack)->next = ft_lstnew (1);
// 	// rev_rotate (stack, 1);
// 	t_node *last = ft_lstlast (stack);
// 	t_node *befo= before_the_last (stack);
// 	printf ("last = %d  befor = %d\n",last->data,befo->data);
// 	ft_free_a_stack (stack);
// }
