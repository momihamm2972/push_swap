/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:28:34 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/02 18:39:57 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"
//rak dayeeer strdup machi dupstr

char	*dupstr(char *s1)
{
	int		len;
	char	*str;
	int		indx;

	len = contline(s1);
	str = my_calloc (len + 1, sizeof(char));
	indx = 0;
	if (!str)
		return (NULL);
	while (indx < len)
	{
		str[indx] = s1[indx];
		indx++;
	}
	return (str);
}

char	*my_join(char *s1, char *s2)
{
	char	*str1;
	char	*str2;
	size_t	indx_of_conca;
	char	*buff;
	size_t	indx;

	if (!s1)
		s1 = dupstr("");
	str1 = (char *)s1;
	str2 = (char *)s2;
	indx_of_conca = 0;
	buff = malloc(contline(str1) + contline(str2) + 1);
	if (!buff)
		return (NULL);
	indx = 0;
	while (s1[indx] != '\0')
	{
		buff[indx] = str1[indx];
		indx++;
	}
	while (indx < (contline(str1) + contline(str2)))
		buff[indx++] = str2[indx_of_conca++];
	buff[indx] = '\0';
	return (free(s1), buff);
}

size_t	contline(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*my_sawebstr(char *s, unsigned int start, size_t len)
{
	char	*alloc_adds;
	size_t	str_len;
	size_t	indx;
	size_t	end;

	if (!s)
		return (NULL);
	str_len = contline (s);
	if (start >= str_len)
		return (my_calloc(1, sizeof(char)));
	if (len > contline(&s[start]))
		len = contline(&s[start]);
	alloc_adds = (char *) my_calloc(len + 1, sizeof(char));
	if (!alloc_adds)
		return (NULL);
	indx = 0;
	end = start + len;
	while (start < end && indx < len + 1 && s[start])
		alloc_adds[indx++] = s[start++];
	return (alloc_adds);
}

void	*my_calloc(size_t count, size_t size)
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
