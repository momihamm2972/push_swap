/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:58:05 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/17 22:33:14 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_double (t_node **stack, int num)
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

void	make_args_usefull (t_parss *my_struct)
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
	free (my_struct->arg1);
}
