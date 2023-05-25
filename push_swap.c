/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:58:11 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/25 21:36:52 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	if (ac >= 2)
	{
		// char **args;
		int i = 1;
		while (av[i] != NULL)
		{
			printf ("%s\t",av[i]);
			i++;
		} 
		// printf("wiwi\n%s\n",av[1]);
	}
	else
		printf("mimi\n");
}