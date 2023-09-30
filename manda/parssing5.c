/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:58:05 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/01 00:27:25 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_are_sorted(t_node **stack)
{
	t_node	*ptr;

	ptr = (*stack);
	while (ptr)
	{
		if ((ptr->next != NULL) && ptr->data > ptr->next->data)
			return ;
		ptr = ptr->next;
	}
	exit (0);
}

void	ft_double(t_node **stack, int num)
{
	t_node	*ptr;
	int		doub;

	ptr = (*stack);
	doub = 0;
	while (ptr)
	{
		if (ptr->data == num)
			doub++;
		if (doub > 1)
			exit (error_msg ());
		ptr = ptr->next;
	}
}

int	only_sing(char *str)
{
	if ((ft_strlen (str) == 1) && (str[0] == '-' || str[0] == '+'))
		return (-91);
	return (0);
}

// int	*bubble(int *arr, int size)
// {
// 	int indx;
// 	int	swap;

// 	indx = 0;
// 	while (indx < size)
// 	{
// 		if (indx + 1 < size && arr[indx] > arr[indx + 1])
// 		{
// 			swap = arr[indx];
// 			arr[indx] = arr[indx + 1];
// 			arr[indx + 1] = swap;
// 			indx = -1;
// 		}
// 		indx++;
// 	}
// 	return (arr);
// }

// int	find_position (int *arr, int nb)
// {
// 	int indx;

// 	indx = 0;
// 	while (indx < 3)
// 	{
// 		if (arr[indx] == nb)
// 			return (indx);
// 		indx++;
// 	}
// 	return (-1);
// }

// void	ft_tree_complet(t_node **stack)
// {
// 	if ((*stack)->position == 1 && (*stack)->next->position == 0
// 		&& (*stack)->next->next->position == 2)
// 	{
// 		swap_2_elements (stack, 0);
// 	}
// 	else if ((*stack)->position == 2 && (*stack)->next->position == 1
// 		&& (*stack)->next->next->position == 0)
// 	{
// 		swap_2_elements (stack, 0);
// 		rev_rotate (stack, 0);
// 	}
// 	else if ((*stack)->position == 2 && (*stack)->next->position == 0
// 		&& (*stack)->next->next->position == 1)
// 	{
// 		rotate (stack, 0);
// 	}
// 	else if ((*stack)->position == 0 && (*stack)->next->position == 2
// 		&& (*stack)->next->next->position == 1)
// 	{
// 		swap_2_elements (stack, 0);
// 		rotate (stack, 0);
// 	}
// 	else if ((*stack)->position == 1 && (*stack)->next->position == 2
// 		&& (*stack)->next->next->position == 0)
// 	{
// 		rev_rotate (stack, 0);
// 	}
// 	print_nodes (stack);
// }

// void	ft_tree(t_node	**stack)
// {
// 	t_node	*ptr;
// 	int		*arr;
// 	int		indx;

// 	ptr = (*stack);
// 	arr = (int *) malloc (sizeof (int) * 3);
// 	indx = 0;
// 	while (ptr)
// 	{
// 		arr[indx] = ptr->data;
// 		indx++;
// 		ptr = ptr->next;
// 	}
// 	arr = bubble (arr, 3);
// 	ptr = (*stack);
// 	indx = 0;
// 	while (ptr)
// 	{
// 		ptr->position = find_position (arr, ptr->data);
// 		ptr = ptr->next;
// 	}
// 	free (arr);
// 	ft_tree_complet (stack);
// }

// void	five(t_parss *airbag)
// {
// 	if (ft_lstsize ((*airbag->stack_a)) == 2)
// 	{
// 		// printf ("2\n");
// 		swap_2_elements ((airbag->stack_a), 0);
// 		print_nodes (airbag->stack_a);
// 		exit (0);
// 	}
// 	else if (ft_lstsize ((*airbag->stack_a)) == 3)
// 	{
// 		ft_tree (airbag->stack_a);
// 		// printf ("3\n");
// 		exit (0);
// 	}
// 	else if (ft_lstsize ((*airbag->stack_a)) == 4)
// 	{
// 		printf ("4\n");
// 	}
// 	else if (ft_lstsize ((*airbag->stack_a)) == 5)
// 	{
// 		printf ("5\n");
// 	}
// }

void	make_args_usefull(t_parss *my_struct)
{
	int	num;
	int	indx;

	indx = 0;
	num = 0;
	my_struct->stack_a = malloc (sizeof (t_node *));
	my_struct->arg2 = ft_split (my_struct->arg1, '$');
	(*my_struct->stack_a) = ft_lstnew (ft_atoi (my_struct->arg2[indx]));
	while (my_struct->arg2[++indx])
	{
		num = ft_atoi (my_struct->arg2[indx]);
		ft_lstadd_back (my_struct->stack_a, ft_lstnew (num));
		ft_double (my_struct->stack_a, num);
	}
	if (ft_lstsize ((*my_struct->stack_a)) <= 5)
	{
		// printf ("swap\n");
		five (my_struct);
	}
	ft_are_sorted (my_struct->stack_a);
	free (my_struct->arg1);
}
