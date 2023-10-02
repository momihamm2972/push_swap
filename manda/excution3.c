/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:13:15 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/02 07:13:57 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	print_lis(t_node **stacka)
{
	t_node	*ptr;
	void	*bebe;

	bebe = (void *)0xbebebebebebebebe;
	ptr = (*stacka);
	while (ptr)
	{
		ptr = ptr->next;
		if (ptr == bebe)
			ptr = NULL;
	}
	ptr = (*stacka);
}

int	min_value(t_node **stack)
{
	t_node	*ptr;
	int		min;

	if (!(*stack))
		return (2147483647);
	ptr = (*stack);
	min = ptr->data;
	while (ptr)
	{
		if (min > ptr->data)
			min = ptr->data;
		ptr = ptr->next;
	}
	return (min);
}

int	big_value(t_node **stack)
{
	t_node	*ptr;
	int		big;

	ptr = (*stack);
	if (!ptr)
		return (-2147483648);
	big = ptr->data;
	while (ptr)
	{
		if (ptr->data > big)
			big = ptr->data;
		ptr = ptr->next;
	}
	return (big);
}

void	indxy_stack(t_node **stack)
{
	t_node	*ptr;
	int		indx;

	ptr = (*stack);
	indx = 0;
	while (ptr)
	{
		ptr->indx_of_node = indx;
		indx++;
		ptr = ptr->next;
	}
}
