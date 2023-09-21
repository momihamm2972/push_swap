/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:37 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/21 04:30:31 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*an_node(t_node **stack, int nb)
{
	t_node	*ptr;

	ptr = (*stack);
	while (ptr)
	{
		if (ptr->data == nb)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

void	make_it_top(t_node **stack, int info, int porn)
{
	if (porn > 0)
	{
		while ((*stack)->data != info)
			rotate (stack, 1);
		indxy_stack (stack);
	}
	else if (porn < 0)
	{
		while ((*stack)->data != info)
			rev_rotate (stack, 1);
		indxy_stack (stack);
	}
}
