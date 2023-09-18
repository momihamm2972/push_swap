/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:57:53 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/18 19:58:14 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_all(char **s, int ptrs)
{
	int	indx;

	indx = 0;
	while (indx < ptrs)
	{
		free (s[indx]);
		indx++;
	}
	free(s);
}

int	num_of_word(char *s, char c)
{
	int		indx;
	int		len;

	indx = 0;
	len = 0;
	if (s[indx] == '\0')
		return (0);
	while (s[indx])
	{
		if (s[indx] != c)
		{
			len++;
			while (s[indx] != c && s[indx])
				indx++;
			indx--;
		}
		indx++;
	}
	return (len);
}

char	**ft_split(char *s, char c)
{
	char	**spl;
	int		r_s_e_c[4];

	if (!s)
		return (NULL);
	r_s_e_c[0] = -1;
	r_s_e_c[1] = 0;
	r_s_e_c[2] = 0;
	r_s_e_c[3] = num_of_word((char *)s, c);
	spl = (char **) ft_calloc ((r_s_e_c[3] + 1), sizeof(char *));
	if (!spl)
		return (NULL);
	while (++r_s_e_c[0] < r_s_e_c[3])
	{
		while (s[r_s_e_c[2]] && s[r_s_e_c[2]] == c)
			r_s_e_c[2]++;
		r_s_e_c[1] = r_s_e_c[2];
		while (s[r_s_e_c[2]] && s[r_s_e_c[2]] != c)
			r_s_e_c[2]++;
		spl[r_s_e_c[0]] = ft_substr(s, r_s_e_c[1], (r_s_e_c[2] - r_s_e_c[1]));
		if (!spl[r_s_e_c[0]])
			return (free_all(spl, r_s_e_c[3]), NULL);
		r_s_e_c[1] = r_s_e_c[2];
	}
	return (spl);
}

int	error_msg(void)
{
	write (2, "Error 404!!\n", 12);
	return (0);
}
