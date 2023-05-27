/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:58:11 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/26 21:13:50 by momihamm         ###   ########.fr       */
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
		char **arg2;
		int i = 1;
		arg1 = malloc (1);
		while (av[i] != NULL)
		{
			if (ft_check_if_str_has_wrong_char(av[i],' ') == 1)
			{
				arg1 = ft_strjoin(arg1, split_the_str(av[i]));
				arg1 = ft_strjoin(arg1,"$"); 	
			}
			else
			{
				arg1 = ft_strjoin(arg1, av[i]);
				arg1 = ft_strjoin(arg1, "$");
			}
			// printf ("%s\n",arg1);
			
		// 	// printf ("%s\t",av[i]);
			i++;
		} 
		// printf ("%s",arg1);
		// // printf("wiwi\n%s\n",av[1]);
		arg2 = ft_split(arg1, '$');
		int j = 0;
		while (arg2[j])
			printf("%s\n",arg2[j++]);
	}
	else
		printf("mimi\n");
}