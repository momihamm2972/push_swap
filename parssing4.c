/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:58:02 by momihamm          #+#    #+#             */
/*   Updated: 2023/06/14 04:29:33 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char    *arg_v_r(char *str)
{
    if (istheargincowt (str) == 1 || istheargincowt (str) == 0)
    {
        if (empty_arg(str) == 1)
        {
            if (ft_isdigit (str) == 0)
            {
                if (sing_of_arg (str) == 0)
                    str = make_the_str_can_splited (str);
                else
                    exit (error_msg ());
            }
            else
                exit (error_msg ());
        }
        else
            exit (error_msg ());
    }
    return (str);
}

char *finale_char (char *str)
{
    char *final;

    final = malloc (1);
    str = arg_v_r (str);
    final = ft_strjoin (final, str);
    final = ft_strjoin (final, "$$");
    return (final);
}