/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:42:06 by momihamm          #+#    #+#             */
/*   Updated: 2023/06/14 04:29:38 by momihamm         ###   ########.fr       */
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

int main (int ac, char **av)
{
    if (ac >= 2)
    {
        t_parss *parssing;
        t_node *head;

        parssing = malloc (sizeof (t_parss));
        head = malloc (sizeof (t_node));
        parssing->arg1 = malloc (1);
        parssing->indx_of_arg = 0;
        while (av[++parssing->indx_of_arg])
            parssing->arg1 = ft_strjoin (parssing->arg1, finale_char (av[parssing->indx_of_arg]));
        // printf ("#%s\n",parssing->arg1);
        parssing->arg2 = ft_split (parssing->arg1, '$');
        parssing->indx = 0;
        head->data = ft_atoi (parssing->arg2[parssing->indx]);
        while (parssing->arg2[++parssing->indx])
            ft_lstadd_back(&head, ft_lstnew (ft_atoi(parssing->arg2[parssing->indx])));
        print_nodes (&head);
    }
}