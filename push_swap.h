/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:55:00 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/30 22:59:16 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
	int		data;
	int		position;
	struct node	*next;
}t_node;

/*#################### struct of parssing ##########################*/
typedef struct parss
{
	char	*arg1;
	char	**arg2;
	int		indx;
}t_parss;
/*##################################################################*/

t_node	*ft_lstnew(int content);
t_node	*ft_lstlast(t_node *head);
int	ft_lstsize(t_node *head);
void ft_lstadd_back(t_node **lst, t_node *new);
char	*ft_strjoin(char const *s1, char const *s2);
int ft_check_if_str_has_wrong_char(char *str, char c);
char *split_the_str(char *str);
int ft_strlen(char *str);
void	*ft_calloc(size_t count, size_t size);
void	free_all(char **s, int ptrs);
int	num_of_word(char *s, char c);
char	**ft_split(char *s, char c);
char	*ft_substr(char *s, int start, int len);
int	ft_isalpha(int c);
int ft_isdigit(int c);
long long ft_atoi (char *str);
void check_duble(long long *arr, int num);
int check_the_arg_(char *str);
int sing_in_str(char *str);

#endif