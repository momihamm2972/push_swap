/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:19:44 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/02 22:58:57 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"

void	out(void)
{
	write (2, "Error\n", 6);
	exit (0);
}

void	application(t_parss *my_struct, char *line)
{
	if (ft_strcmp (line, "sa\n") == 0)
		swap_2_elements (my_struct->stack_a);
	else if (ft_strcmp (line, "sb\n") == 0)
		swap_2_elements (my_struct->stack_b);
	else if (ft_strcmp (line, "ss\n") == 0)
		ss (my_struct->stack_a, my_struct->stack_b);
	else if (ft_strcmp (line, "ra\n") == 0)
		rotate (my_struct->stack_a);
	else if (ft_strcmp (line, "rb\n") == 0)
		rotate (my_struct->stack_b);
	else if (ft_strcmp (line, "rr\n") == 0)
		rr (my_struct->stack_a, my_struct->stack_b);
	else if (ft_strcmp (line, "rra\n") == 0)
		rev_rotate (my_struct->stack_a);
	else if (ft_strcmp (line, "rrb\n") == 0)
		rev_rotate (my_struct->stack_b);
	else if (ft_strcmp (line, "rrr\n") == 0)
		rrr (my_struct->stack_a, my_struct->stack_b);
	else if (ft_strcmp (line, "pa\n") == 0)
		push_to_stack (my_struct->stack_b, my_struct->stack_a);
	else if (ft_strcmp (line, "pb\n") == 0)
		push_to_stack (my_struct->stack_a, my_struct->stack_b);
	else
		out ();
}

void	ft_read(t_parss *my_struct)
{
	char	*line;
	char	*ptr;

	while (1)
	{
		line = get_next_line (0);
		ptr = line;
		if (!line)
			break ;
		application (my_struct, line);
		free (ptr);
	}
}

void	excut(t_parss *my_struct)
{
	make_args_usefull (my_struct);
	my_struct->stack_b = malloc (sizeof (t_node *));
	if (!my_struct->stack_b)
		return ;
	(*my_struct->stack_b) = NULL;
	ft_read (my_struct);
	if (is_sorted (my_struct->stack_a) == 0 && (*my_struct->stack_b) == NULL)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	ft_free_a_stack (my_struct->stack_b);
}

int	main(int ac, char **av)
{
	t_parss	*pars;

	if (ac >= 2)
	{
		pars = malloc (sizeof (t_parss));
		if (!pars)
			return (0);
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
		excut (pars);
		ft_free_a_stack (pars->stack_a);
	}
	exit(0);
}
