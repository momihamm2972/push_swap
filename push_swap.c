/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:58:11 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/25 22:15:56 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	(void) av;
	if (ac >= 2)
	{
		// printf ("%s\n",ft_strjoin("pnl ", "music91"));
		char *arg1;
		int i = 1;
		arg1 = malloc (1);
		while (av[i] != NULL)
		{
			arg1 = ft_strjoin(arg1, av[i]);
			arg1 = ft_strjoin(arg1, "$");
			printf ("%s\n",arg1);
			
			// printf ("%s\t",av[i]);
			i++;
		} 
		printf ("%s",arg1);
		// printf("wiwi\n%s\n",av[1]);
	}
	else
		printf("mimi\n");
}