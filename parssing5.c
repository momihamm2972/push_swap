/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:58:05 by momihamm          #+#    #+#             */
/*   Updated: 2023/06/16 11:35:32 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_an_arr (int *arr, int len)
{
    int indx;
    int swap;

    indx = 0;
    while (indx < len)
    {
        if ((arr[indx] > arr[indx + 1]) && (indx + 1 < len))
        {
            swap = arr[indx];
            arr[indx] = arr[indx + 1];
            arr[indx + 1] = swap;
            indx = -1;
        }
        indx++;
    }
}

void position01_nodes (t_parss *my_sc, t_node *stack)
{
	t_node	*ptr;
	int		indx;

	ptr = stack;
	while (ptr)
	{
		indx = 0;
		while (indx < my_sc->len_of_arr)
		{
			if (my_sc->beforsorted[indx] == ptr->data)
				ptr->position = indx;
			indx++;
		}
		ptr = ptr->next;
	}
}

int*	position00_nodes (int len_of_arr, t_node *stack)
{
    t_node	*ptr;
    int     *arr_of_int;
    int     indx;

	ptr = stack;
	arr_of_int = (int *) malloc (4 * len_of_arr);
    indx = 0;
    while (indx < len_of_arr)
    {
        arr_of_int[indx] = ptr->data;
		ptr = ptr->next;
		indx++;
    }
	return (arr_of_int);
}

void    parssing (t_parss *my_struct)
{
    t_node *head;

    head = malloc (sizeof (t_node));
    my_struct->arg2 = ft_split (my_struct->arg1, '$');
    my_struct->len_of_arr = 0;
    my_struct->indx = 0;
    head->data = ft_atoi (my_struct->arg2[my_struct->indx]);
    while (my_struct->arg2[++my_struct->indx])
        {
            ft_lstadd_back(&head, ft_lstnew (ft_atoi(my_struct->arg2[my_struct->indx])));
            ft_double (&head, ft_atoi(my_struct->arg2[my_struct->indx]));
        }
        my_struct->len_of_arr = my_struct->indx;
        sorted (&head);
		my_struct->beforsorted = position00_nodes (my_struct->len_of_arr, head);
		sort_an_arr (my_struct->beforsorted, my_struct->len_of_arr);
		position01_nodes (my_struct, head);
        first_trys (my_struct, &head);
        // print_nodes (&head);//hna ***********************;
}

