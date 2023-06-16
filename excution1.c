/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:27 by momihamm          #+#    #+#             */
/*   Updated: 2023/06/16 13:00:32 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int finally_sorted (t_node **stack)
{
	t_node	*tmp;
	int		indx;
	
	if (!(*stack))
		return (1);
	tmp = (*stack);
	if (tmp->position == 0)
		indx = 1;
	else
		return (1);
	while (tmp)
	{
		tmp = tmp->next;
		if ((tmp != NULL) && (tmp->position != indx))
			return (1);
		indx++;	
	}
	return (0);
}
