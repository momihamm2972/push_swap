/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:56 by momihamm          #+#    #+#             */
/*   Updated: 2023/07/16 02:57:19 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*before_the_last(t_node **stack)
{
		t_node *ptr;

	if (!(*stack))
		return (NULL);
	ptr = (*stack);
    while (ptr->next)
    {
        if (ptr->next->next->next == NULL)
            return (ptr->next);
        ptr = ptr->next;
    }
    return (NULL);
}

void    print_nodes(t_node **stack)
{
    int key_of_list;
    t_node *tmp;

    if (!(*stack))
        return;
    key_of_list = 0;
    tmp = (*stack);
    printf ("node=>%d========|==>data==%d>>>>>>>>>Position%d\n",key_of_list, tmp->data, tmp->position);
    while (tmp->next)
    {
        key_of_list++;
        printf ("node=>%d==========>data==%d>>>>>>>>>Position%d\n",key_of_list, tmp->next->data, tmp->next->position);
        tmp = tmp->next;
    }
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