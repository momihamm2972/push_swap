/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:58:05 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/01 07:59:04 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int only_sing(char *str)
{
    if ((ft_strlen (str) == 1) && (str[0] == '-' || str[0] == '+'))
        return (-91);
    return (0);
}

void    make_args_usefull (t_parss *my_struct)
{
    my_struct->arg2 = ft_split (my_struct->arg1, '$');
    int i = 0;
    while (my_struct->arg2[i])
        printf ("%s\n",my_struct->arg2[i++]);
    int j= 0;
    my_struct->beforsorted = (int *) ft_calloc (i, sizeof (int));
    while (j < i)
    {
        
        my_struct->beforsorted[j] = ft_atoi (my_struct->arg2[j]);
        printf ("NUM <%d>\n",my_struct->beforsorted[j]);
        j++;
    }
}

