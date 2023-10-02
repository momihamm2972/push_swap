/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonusparss4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:19:20 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/02 20:43:03 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"

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

void	make_args_usefull(t_parss *my_struct)
{
	int	num;
	int	indx;

	indx = 0;
	num = 0;
	my_struct->stack_a = malloc (sizeof (t_node *));
	if (!my_struct->stack_a)
		return ;
	my_struct->arg2 = ft_split (my_struct->arg1, '$');
	(*my_struct->stack_a) = ft_lstnew (ft_atoi (my_struct->arg2[indx]));
	while (my_struct->arg2[++indx])
	{
		num = ft_atoi (my_struct->arg2[indx]);
		ft_lstadd_back (my_struct->stack_a, ft_lstnew (num));
		ft_double (my_struct->stack_a, num);
	}
	ft_are_sorted (my_struct->stack_a);
	free (my_struct->arg1);
}
