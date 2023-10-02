/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonusparss5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:19:25 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/02 21:15:46 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"

void	indxy_stack(t_node **stack)
{
	t_node	*ptr;
	int		indx;

	ptr = (*stack);
	indx = 0;
	while (ptr)
	{
		ptr->indx_of_node = indx;
		indx++;
		ptr = ptr->next;
	}
}

t_node	*min_value_in(t_node **stack)
{
	t_node	*ptr;
	t_node	*node;
	int		min;

	ptr = (*stack);
	if (!ptr)
		return (NULL);
	node = ptr;
	min = ptr->data;
	while (ptr)
	{
		if (ptr->data < min)
		{
			min = ptr->data;
			node = ptr;
		}
		ptr = ptr->next;
	}
	return (node);
}

int	is_sorted(t_node **stack)
{
	t_node	*ptr;

	ptr = (*stack);
	if (!ptr)
		return (-1);
	while (ptr)
	{
		if ((ptr->next != NULL) && ptr->data > ptr->next->data)
			return (-1);
		ptr = ptr->next;
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			indx;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	indx = 0;
	while ((str1[indx] || str2[indx]))
	{
		if (str1[indx] != str2[indx])
			return (str1[indx] - str2[indx]);
		indx++;
	}
	return (0);
}
