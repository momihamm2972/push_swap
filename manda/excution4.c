/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:37 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/24 05:47:28 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	an_node (t_node **stack, int info)
{
	t_node	*ptr;

	ptr = (*stack);
	while (ptr)
	{
		if (ptr->data == info)
		{
			if (ptr->indx_of_node <= (ft_lstsize ((*stack)) / 2))
			{
				ptr->moves_b = ptr->indx_of_node;
			}
			else if (ptr->indx_of_node >= (ft_lstsize ((*stack)) / 2))
			{
				ptr->moves_b = ft_lstsize ((*stack)) - ptr->indx_of_node;
				ptr->moves_b *= -1;
			}
		}
		ptr = ptr->next;
	}
}

void	if_min_max_in_b (t_parss *azalim)
{
	if (min_value (azalim->stack_b) < min_value (azalim->stack_a))
		an_node (azalim->stack_b, min_value (azalim->stack_b));
	if (big_value (azalim->stack_b) > big_value (azalim->stack_a))
		an_node (azalim->stack_b, big_value (azalim->stack_b));
}