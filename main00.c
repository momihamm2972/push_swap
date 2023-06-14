/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:36:25 by momihamm          #+#    #+#             */
/*   Updated: 2023/06/14 02:03:35 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

int main(void)
{
    printf ("%d",sing_of_arg("                             -78   323                       "));
}