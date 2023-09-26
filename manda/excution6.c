/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:44 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/26 07:19:57 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void    node_of_top (t_node **stack, int info)
// {
    
// }

t_node  *second_node (t_node **stack, int info)
{
    t_node  *ptr;

    ptr = (*stack);
    while (ptr)
    {
        if (ptr->data > info)
            return (ptr);
        ptr = ptr->next;
    }
    return (NULL);
}

t_node  *at_least (t_node **stack)
{
    t_node  *ptr;
    t_node  *less;
    int     min;

    ptr = (*stack);
    min = ptr->moves_b;
    while (ptr)
    {
        if (min > ptr->moves_b)
        {
            min = ptr->moves_b;
            less = ptr;
        }
        ptr = ptr->next;
    }
    return (less);
}