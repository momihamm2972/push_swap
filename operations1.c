/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 00:38:47 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/07 17:54:20 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rev_rotate (t_node **stack, int delta)
{
	t_node *the_last;
	(void)delta;
	t_node *new_last;
	
	if (!(*stack))
		return ;
	the_last = ft_lstlast (stack);
	new_last = before_the_last(stack);
	the_last->next = (*stack);
	(*stack) = new_last->next;
	new_last->next = NULL;
	// if (delta == 0)
	// 	write (1, "rra\n", 4);
	// else if (delta == 1)
	// 	write (1, "rrb\n", 4);
}

void	rrr (t_node **stack_a, t_node **stack_b)
{
	rev_rotate (stack_a, 2);
	rev_rotate (stack_b, 2);
	// write (1, "rrr\n", 4);
}



// int main ()
// {
// 	t_node *head =  ft_lstnew (32);
// 	head->indx_of_stack = 2;
// 	head->next = ft_lstnew (33);
// 	head->next->indx_of_stack = 1;
// 	head->next->next = ft_lstnew (12);
// 	head->next->next->indx_of_stack = 3;
// 	head->next->next->next = ft_lstnew (43);
// 	head->next->next->next->indx_of_stack = 4;
// 	t_node *ptr = find_the_small_indx_of_stack(&head);
// 	printf ("%d",ptr->data);
// }
