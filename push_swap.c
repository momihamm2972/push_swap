/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:58:11 by momihamm          #+#    #+#             */
/*   Updated: 2023/06/01 21:39:50 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	// (void) av;
	// printf ("%s",av[1]);
	if (ac >= 2)
	{
		t_node *head;
		t_parss *parssing;
		parssing = malloc (sizeof(t_parss));
		// char *arg1;
		// char **arg2;
		int i = 1;
		parssing->arg1 = malloc (1);
		while (av[i] != NULL)
		{
			if (sing_in_str(av[i]) == 0)
			{
				if (ft_check_if_str_has_wrong_char(av[i],' ') == 1)
				{
					parssing->arg1 = ft_strjoin(parssing->arg1, split_the_str(av[i]));
					parssing->arg1 = ft_strjoin(parssing->arg1,"$"); 	
				}
				else
				{
					parssing->arg1 = ft_strjoin(parssing->arg1, av[i]);
					parssing->arg1 = ft_strjoin(parssing->arg1, "$");
				}
			}
			else
			{
				write (1, "Error 500\n", 10);
				exit(0);
			}
			i++;
		}
		if (check_the_arg_(parssing->arg1) == 1)
			exit(printf ("456\n"));
		parssing->arg2 = ft_split(parssing->arg1, '$');
		// printf ("04");
		/*##################print the 2d array###########################*/
		int j = 0;
		while (parssing->arg2[j])
			j++;
			// printf("%s\n",parssing->arg2[j++]);
		// printf ("/*###############################################################*/\n");
		long long lenof2d [j-1];
		j = -1;
		while (parssing->arg2[++j])
		{

			lenof2d[j] = ft_atoi(parssing->arg2[j]);
			// printf ("*%lld\n",lenof2d[j]);
			if (lenof2d[j] > 2147483647 || lenof2d[j] < -2147483648)
			{
				// printf ("%lld$",lenof2d[j]);
				write (2 ,"Error 201\n", 10);
				// printf ("")
				exit (0);
			}
			if (j >= 1)
			{
				// printf ("dkhel%lld\n",lenof2d[j]);
				check_duble(lenof2d, lenof2d[j]);
			}
			// 	j++;
		}
		j=0;
		while (lenof2d[j])
			j++;
			// printf("*%lld\n",lenof2d[j++]);
		head = ft_lstnew((int)lenof2d[0]);
		j = 1;
		while (lenof2d[j])
		{
			ft_lstadd_back(&head, ft_lstnew(lenof2d[j]));
			j++;
		}
		// printf ("size ++>%d\n",ft_lstsize(head));

		// printf("####%d$$$$$$",head->data);
	}
	else
		write (2, "Error 404 : at least one argument must be taken!!\n", 50);
}