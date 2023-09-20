/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:13:15 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/20 18:22:44 by momihamm         ###   ########.fr       */
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

int	min_value_in_the_stack (t_node **stack)
{
	t_node *ptr;
	int min;

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

void	Calculator_moves_min_b(t_node **stack, int min)
{
	t_node	*ptr;
	// int		moves;

	ptr = (*stack);
	while (ptr)
	{
		if (ptr->data == min)
		{
			if ((ft_lstsize ((*stack)) / 2) > ptr->indx_of_node)
			{
				ptr->moves_b = ptr->indx_of_node;
			}
			if ((ft_lstsize ((*stack)) / 2) < ptr->indx_of_node)
			{
				ptr->moves_b = ft_lstsize ((*stack)) - ptr->indx_of_node;
				ptr->moves_b *= -1;
			}
		}
		ptr = ptr->next;
	}
	
}

// void	what_if_the_min_value_in_stackb(t_node **stack_a, t_node **stack_b)
// {
// 	if (min_value_in_the_stack (stack_b) < min_value_in_the_stack (stack_a))
// 	{
		
// 	}
// }