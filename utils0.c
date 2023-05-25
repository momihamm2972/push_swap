/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:41:21 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/25 21:44:52 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*buff;
	int		indx_of_conca;
	int		indx;

	if (!s1 || !s2)
		return (NULL);
	str1 = (char *)s1;
	str2 = (char *)s2;
	indx_of_conca = 0;
	buff = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!buff)
		return (NULL);
	indx = 0;
	while (s1[indx] != '\0')
	{
		buff[indx] = str1[indx];
		indx++;
	}
	while (indx < (ft_strlen(str1) + ft_strlen(str2)))
		buff[indx++] = str2[indx_of_conca++];
	buff[indx] = '\0';
	return (buff);
}