/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonusparss1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:17:51 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/02 20:41:29 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"

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
