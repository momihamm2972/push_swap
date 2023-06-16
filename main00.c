/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:25 by momihamm          #+#    #+#             */
/*   Updated: 2023/06/16 02:54:08 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*str;
	size_t	indx;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	str = (char *)ptr;
	indx = 0;
	while (indx < (count * size))
		str[indx++] = 0;
	return (ptr);
}


void	*ft_memcpy(void *to, const void *from, size_t len)
{
	char	*to0;
	char	*from0;
	size_t	i;

	if (!to && !from)
		return (NULL);
	to0 = (char *)to;
	from0 = (char *)from;
	i = 0;
	while (i < len)
	{
		to0[i] = from0[i];
		i++;
	}
	return (to0);
}

char	*ft_strdup(char *s1)
{
	size_t	len;
	char	*str;

	len = ft_strlen(s1);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len);
	return (str);
}

int istheargincowt (char *str)
{
    int indx;

    indx = 0;
    while (str[indx])
    {
        if (str[indx] == 32)
            return (1);
        indx++;
    }
    return (0);
}

int sing_of_arg (char *str)
{
    int indx;

    indx = 1;
    while (str[indx])
    {
        if (str[indx] == '-' || str[indx] == '+')
        {
            if (str[indx + 1] == 32 || str[indx - 1] != 32)
                return (1);
        }
        indx++;
    } 
    return (0);
}

int ft_isdigit (char *str)
{
    int indx;

    indx = 0;
    while (str[indx])
    {
        if ((str[indx] >= 48 && str[indx] <= '9') || str[indx] == 32
        || str[indx] == '+' || str[indx] == '-')
            indx++;
        else
            return (1);
    }
    return (0);
}

char *make_the_str_can_splited (char *str)
{
    int indx;
    char *dup;
    
    indx = 0;
    dup = ft_strdup (str);
    while (dup[indx])
    {
        if (dup[indx] == 32)
            dup[indx] = '$';
        indx++;
    }
    return (dup);
}
// argument khawi 3endak tnsahh;
int empty_arg (char *str)
{
    int indx;

    indx = 0;
    while (str[indx])
    {
        if (str[indx] != 32)
            return (1);
        indx++;
    }
    return (0);
}

// int ft_double(t_node **stack, int data)
// {
//     t_node *ptr;
//     int cont;

//     ptr = (*stack);
//     cont = 0;
//     while (ptr)
//     {
//         if (ptr->data == data)
//             cont++;
//         if (cont > 1)
//             exit (error_msg ());
//         ptr = ptr->next;
//     }
//     return (0);
// }

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
    indx = 0;
    while (indx < len)
        printf ("%d\t",arr[indx++]);
}

int main(void)
{
    int arr[] = {1,3,2,45,0,6,5,8, 786 , 13 , 91,2001, 1899};
    // 1 2 3
    // 1 2 3 45 0
    // 1 2 3 0 45
    // 0 1 2 3 45
    // arr[0]= 0;
    // arr[1] = 8;
    int len = sizeof (arr)/4;
    
    sort_an_arr (arr, len);
}
