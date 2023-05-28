/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:50 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/28 21:12:13 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_if_str_has_wrong_char(char *str, char c)
{
    int indx;

    indx = 0;
    while (str[indx])
    {
        if (str[indx] == c)
            return (1);
        indx++;
    }
    return (0);
}

char *split_the_str(char *str)
{
    int indx;

    indx = 0;
    while (str[indx])
    {
        if (str[indx] == 32)
            str[indx] = '$';
        while (str[indx] == 32)
            indx++;
        indx++;
    }
    return (str);
}

void check_duble(long long *arr, int num)
{
    int indx;
    int cont;
    // printf ("$$%d",num);
    indx = 0;
    cont = 0;
    while (arr[indx])
    {
        if (arr[indx] == num)
        {
            cont++;
            if (cont > 1)
            {
                // printf ("arr==>%lld$$$$$$$$num==>%d",arr[indx],num);
                write (2, "Error 402\n", 10);
                exit (0);
            }
        }
        indx++;
    }
}

int check_the_arg_(char *str)
{
    int indx;

    indx = 0;
    while (str[indx])
    {
        if (str[indx] != '$')
            return (0);
        indx++;
    }
    return (1);
}