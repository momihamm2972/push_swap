/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:42:06 by momihamm          #+#    #+#             */
/*   Updated: 2023/06/15 04:16:40 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// char    *arg_v_r(char *str)
// {
//     if (istheargincowt (str) == 1 || istheargincowt (str) == 0)
//     {
//         if (empty_arg(str) == 1)
//         {
//             if (ft_isdigit (str) == 0)
//             {
//                 if (sing_of_arg (str) == 0)
//                     str = make_the_str_can_splited (str);
//                 else
//                     exit (error_msg ());
//             }
//             else
//                 exit (error_msg ());
//         }
//         else
//             exit (error_msg ());
//     }
//     return (str);
// }

// char *finale_char (char *str)
// {
//     char *final;

//     final = malloc (1);
//     str = arg_v_r (str);
//     final = ft_strjoin (final, str);
//     final = ft_strjoin (final, "$$");
//     return (final);
// }
void    parssing (t_parss *my_struct)
{
    t_node *head;

    head = malloc (sizeof (t_node));
    my_struct->arg2 = ft_split (my_struct->arg1, '$');
    my_struct->indx = 0;
    head->data = ft_atoi (my_struct->arg2[my_struct->indx]);
    while (my_struct->arg2[++my_struct->indx])
        {
            ft_lstadd_back(&head, ft_lstnew (ft_atoi(my_struct->arg2[my_struct->indx])));
            ft_double (&head, ft_atoi(my_struct->arg2[my_struct->indx]));
        }
        sorted (&head);
        print_nodes (&head);
}
int main (int ac, char **av)
{
    if (ac >= 2)
    {
        t_parss *pars;

        pars = malloc (sizeof (t_parss));
        pars->arg1 = malloc (1);
        pars->indxarg = 0;
        while (av[++pars->indxarg])
            pars->arg1 = ft_strjoin (pars->arg1, finale_char (av[pars->indxarg]));
        parssing (pars);
    }
}