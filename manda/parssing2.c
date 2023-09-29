/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:56 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/29 01:35:32 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*before_the_last(t_node **stack)
{
	t_node	*ptr;

	if (!(*stack))
		return (NULL);
	ptr = (*stack);
	while (ptr)
	{
		if (ptr && ptr->next && ptr->next->next == NULL)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

void	print_nodes(t_node **stack)
{
	t_node	*tmp;
	// int		key_of_list;

	if (!(*stack))
		return ;
	// key_of_list = 0;
	tmp = (*stack);
	while (tmp)
	{
		printf ("inod %d\t",tmp->indx_of_node);
		printf ("data %d\t",tmp->data);
		// printf ("lent %d\t",tmp->length);
		printf ("arei %d\t",tmp->are_in);
		printf ("mova %d\t",tmp->moves_a);
		printf ("movb %d\t",tmp->moves_b);
		printf ("tmov %d\n",tmp->total_moves);
		// printf ("next %p\n",tmp->next);
		// key_of_list++;
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
