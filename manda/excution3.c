/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:13:15 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/21 04:28:00 by momihamm         ###   ########.fr       */
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
		printf ("$%d\t",ptr->data);
		ptr = ptr->next;
		if (ptr == bebe)
			ptr = NULL;
	}
	ptr = (*stacka);
	printf ("\n");
}

int	min_value(t_node **stack)
{
	t_node	*ptr;
	int		min;

	ptr = (*stack);
	min = 0;
	while (ptr)
	{
		if (min > ptr->data)
			min = ptr->data;
		ptr = ptr->next;
	}
	return (min);
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

void	calculator_moves_min_b(t_parss *no7i, int min)
{
	t_node	*ptr;

	ptr = (*no7i->stack_b);
	while (ptr)
	{
		if (ptr->data == min)
		{
			if ((ft_lstsize ((*no7i->stack_b)) / 2) > ptr->indx_of_node)
				ptr->moves_b = ptr->indx_of_node;
			if ((ft_lstsize ((*no7i->stack_b)) / 2) < ptr->indx_of_node)
			{
				ptr->moves_b = ft_lstsize ((*no7i->stack_b));
				ptr->moves_b -= ptr->indx_of_node;
				ptr->moves_b *= -1;
			}
		}
		ptr = ptr->next;
	}
	ptr = an_node ((no7i->stack_b), min);
	make_it_top ((no7i->stack_b), min, ptr->moves_b);
	push_to_stack (no7i->stack_b, no7i->stack_a, 1);
}
