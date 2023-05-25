/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:50 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/25 22:21:21 by momihamm         ###   ########.fr       */
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

char *split_an_arg(char *str, int indx)
{
    
}