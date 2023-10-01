/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution8.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 21:17:58 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/01 08:07:38 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

int	*bubble(int *arr, int size)
{
	int	indx;
	int	swap;

	indx = 0;
	while (indx < size)
	{
		if (indx + 1 < size && arr[indx] > arr[indx + 1])
		{
			swap = arr[indx];
			arr[indx] = arr[indx + 1];
			arr[indx + 1] = swap;
			indx = -1;
		}
		indx++;
	}
	return (arr);
}

int	find_position(int *arr, int nb)
{
	int	indx;

	indx = 0;
	while (indx < 3)
	{
		if (arr[indx] == nb)
			return (indx);
		indx++;
	}
	return (-1);
}

void	ft_tree_complet(t_node **stack)
{
	if ((*stack)->position == 1 && (*stack)->next->position == 0
		&& (*stack)->next->next->position == 2)
		swap_2_elements (stack, 0);
	else if ((*stack)->position == 2 && (*stack)->next->position == 1
		&& (*stack)->next->next->position == 0)
	{
		swap_2_elements (stack, 0);
		rev_rotate (stack, 0);
	}
	else if ((*stack)->position == 2 && (*stack)->next->position == 0
		&& (*stack)->next->next->position == 1)
		rotate (stack, 0);
	else if ((*stack)->position == 0 && (*stack)->next->position == 2
		&& (*stack)->next->next->position == 1)
	{
		swap_2_elements (stack, 0);
		rotate (stack, 0);
	}
	else if ((*stack)->position == 1 && (*stack)->next->position == 2
		&& (*stack)->next->next->position == 0)
		rev_rotate (stack, 0);
}

void	ft_tree(t_node	**stack)
{
	t_node	*ptr;
	int		*arr;
	int		indx;

	ptr = (*stack);
	arr = (int *) malloc (sizeof (int) * 3);
	indx = 0;
	while (ptr)
	{
		arr[indx] = ptr->data;
		indx++;
		ptr = ptr->next;
	}
	arr = bubble (arr, 3);
	ptr = (*stack);
	indx = 0;
	while (ptr)
	{
		ptr->position = find_position (arr, ptr->data);
		ptr = ptr->next;
	}
	free (arr);
	ft_tree_complet (stack);
}

void	five(t_parss *airbag)
{
	ft_are_sorted (airbag->stack_a);
	if (ft_lstsize ((*airbag->stack_a)) == 2)
	{
		swap_2_elements ((airbag->stack_a), 0);
		exit (0);
	}
	else if (ft_lstsize ((*airbag->stack_a)) == 3)
	{
		ft_tree (airbag->stack_a);
		exit (0);
	}
	else if (ft_lstsize ((*airbag->stack_a)) == 4)
	{
		ft_for (airbag);
		exit(0);
	}
	else if (ft_lstsize ((*airbag->stack_a)) == 5)
	{
		ft_five_complet (airbag);
		exit (0);
	}
}
