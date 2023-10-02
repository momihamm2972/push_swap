/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:42:06 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/02 23:05:29 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*min_value_in(t_node **stack)
{
	t_node	*ptr;
	t_node	*node;
	int		min;

	ptr = (*stack);
	if (!ptr)
		return (NULL);
	node = ptr;
	min = ptr->data;
	while (ptr)
	{
		if (ptr->data < min)
		{
			min = ptr->data;
			node = ptr;
		}
		ptr = ptr->next;
	}
	return (node);
}

void	excution(t_parss *excution)
{
	t_node	*p;
	int		big;
	int		m;

	make_the_length_one (excution);
	lis (excution);
	big = find_the_big_length (excution->stack_a);
	check_the_lis_are_in (excution->stack_a, big);
	make_the_lis_in_a (excution);
	if_min_max_in_b (excution);
	ft_all_most (excution);
	rev_or (excution->stack_a);
	m = min_value (excution->stack_a);
	p = min_value_in (excution->stack_a);
	if (!p)
		return ;
	if (p->moves_b > 0)
		while ((*excution->stack_a)->data != m)
			rotate (excution->stack_a, 0);
	else if (p->moves_b < 0)
		while ((*excution->stack_a)->data != m)
			rev_rotate (excution->stack_a, 0);
}

int	main(int ac, char **av)
{
	t_parss	*pars;

	if (ac >= 2)
	{
		pars = malloc (sizeof (t_parss));
		pars->arg1 = ft_strdup("");
		pars->indxarg = 0;
		while (av[++pars->indxarg])
		{
			if (only_sing (av[pars->indxarg]) == -91)
				exit (error_msg ());
			pars->ptr = pars->arg1;
			pars->ptr1 = finale_char (av[pars->indxarg]);
			pars->arg1 = ft_strjoin (pars->arg1, pars->ptr1);
			if (av[pars->indxarg + 1] != NULL)
				free (pars->ptr);
			free (pars->ptr1);
		}
		make_args_usefull (pars);
		if (ft_lstsize(*pars->stack_a) <= 5)
			five (pars);
		else
			excution (pars);
	}
	exit(0);
}
