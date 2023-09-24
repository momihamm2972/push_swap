/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:42:06 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/24 05:29:49 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mr(void)
{
	system ("leaks push_swap");
}

void	excution(t_parss *excution)
{
	int	big;

	make_the_length_one (excution);
	lis (excution);
	big = find_the_big_length (excution->stack_a);
	printf ("\nthe big is %d\n",big);
	check_the_lis_are_in (excution->stack_a, big);
	make_the_lis_in_a (excution);
	if_min_max_in_b (excution);
	print_nodes (excution->stack_a);
	printf ("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	print_nodes(excution->stack_b);
	printf ("minA=%d\n",min_value(excution->stack_a));
	printf ("minB=%d\n",min_value(excution->stack_b));
	printf ("sizeA=%d\nsizeB=%d\n",ft_lstsize ((*excution->stack_a)),ft_lstsize ((*excution->stack_b)));
}

int	main(int ac, char **av)
{
	t_parss	*pars;

	// atexit (mr);
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
		excution (pars);
		// print_nodes (pars->stack_a);
		// free(pars->arg1);
	}
	exit(0);
}
