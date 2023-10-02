/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_bonus2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:25:23 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/02 20:45:27 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"

void	rev_rotate(t_node **stack)
{
	t_node	*the_last;
	t_node	*new_last;

	if (!(*stack))
		return ;
	the_last = ft_lstlast (stack);
	new_last = before_the_last(stack);
	the_last->next = (*stack);
	(*stack) = new_last->next;
	new_last->next = NULL;
	indxy_stack (stack);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rev_rotate (stack_a);
	rev_rotate (stack_b);
}

void	ft_free_a_stack(t_node **stack)
{
	t_node	*ptr0;
	t_node	*ptr1;

	ptr0 = (*stack);
	while (ptr0)
	{
		ptr1 = ptr0->next;
		free (ptr0);
		ptr0 = ptr1;
	}
	free (stack);
}
