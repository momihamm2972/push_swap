/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:58:05 by momihamm          #+#    #+#             */
/*   Updated: 2023/07/21 16:33:23 by momihamm         ###   ########.fr       */
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
				ptr->position = indx + 1;
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

void    free_matrix (char **matrix)
{
    int indx;

    indx = 0;
    while (matrix[indx])
    {
        free (matrix[indx]);
        indx++;
    }
    free (matrix);
}

void    parssing (t_parss *my_struct)
{
    my_struct->head = malloc (sizeof (t_node));
    my_struct->arg2 = ft_split (my_struct->arg1, '$');
    my_struct->len_of_arr = 0;
    my_struct->indx = 0;
    my_struct->head->data = ft_atoi (my_struct->arg2[my_struct->indx]);
    my_struct->head->next = NULL;
    while (my_struct->arg2[++my_struct->indx])
        {
            ft_lstadd_back(&my_struct->head, ft_lstnew (ft_atoi(my_struct->arg2[my_struct->indx])));
            ft_double (&my_struct->head, ft_atoi(my_struct->arg2[my_struct->indx]));
        }
    my_struct->len_of_arr = my_struct->indx;
    sorted (&my_struct->head);
	my_struct->beforsorted = position00_nodes (my_struct->len_of_arr, my_struct->head);
	sort_an_arr (my_struct->beforsorted, my_struct->len_of_arr);
	position01_nodes (my_struct, my_struct->head);
    my_struct->sizeof_stack = ft_lstsize (my_struct->head);
    // free_matrix (my_struct->arg2);
    // free (my_struct->beforsorted);
}

