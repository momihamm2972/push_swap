/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:50 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/26 18:54:48 by momihamm         ###   ########.fr       */
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