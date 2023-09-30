/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution9.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 21:18:03 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/01 00:56:52 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moveto(t_node **stack, int min)
{
	t_node	*ptr;

	ptr = (*stack);
	indxy_stack (stack);
	while (ptr)
	{
		if (ptr->data == min)
		{
			if (ptr->indx_of_node < ft_lstsize ((*stack)) / 2)
				ptr->moves_a = ptr->indx_of_node;
			else if (ptr->indx_of_node >= ft_lstsize ((*stack)) / 2)
			{
				ptr->moves_a = ft_lstsize ((*stack)) - ptr->indx_of_node;
				ptr->moves_a *= -1;
			}
		}
		ptr = ptr->next;
	}
}

void	ft_for(t_parss *sherin)
{
	// t_node *ptr;
	int min;

	// ptr = (*sherin->stack_a);
	min = min_value(sherin->stack_a);
	printf("%d\n", min);
	moveto (sherin->stack_a, min);
	print_nodes (sherin->stack_a);
}