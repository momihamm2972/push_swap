/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:55:00 by momihamm          #+#    #+#             */
/*   Updated: 2023/06/15 00:06:28 by momihamm         ###   ########.fr       */
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
	// int		position;
	struct node	*next;
}t_node;

/*#################### struct of parssing ##########################*/
typedef struct parss
{
	char	*arg1;
	char	**arg2;
	int		indx;
	int		indx_of_arg;
}t_parss;
/*##################################################################*/

t_node	*ft_lstnew(int content);
t_node *ft_lstlast(t_node *lst);
t_node	*before_the_last(t_node **stack);
void	push_to_stack(t_node *stack_0, t_node **stack_1);
void	swap_2_elements(t_node *stack);
void    print_nodes(t_node **stack);
void	rotate (t_node **stack);
void rev_rotate (t_node **stack);
void	rrr (t_node **stack_a, t_node **stack_b);
void	rr (t_node **stack_a, t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void ft_lstadd_back(t_node **lst, t_node *new);
void ft_lstadd_front(t_node **lst, t_node *new);
void	*ft_calloc(size_t count, size_t size);
void	free_all(char **s, int ptrs);
void check_duble(long long *arr, int num);
void	*ft_memcpy(void *to, const void *from, size_t len);
int sipared_arg (char *str);
int ft_double(t_node **stack, int data);
// int ft_lstsize(t_node *lst);
int	ft_lstsize(t_node *head);
int ft_check_if_str_has_wrong_char(char *str, char c);
int ft_strlen(char *str);
int	num_of_word(char *s, char c);
int	ft_isalpha(int c);
int ft_isdigit(char *str);
int ft_isdigit_atoi(int c);
int check_the_arg_(char *str);
int sing_in_str(char *str);
int	error_msg(void);
int empty_arg (char *str);
int sing_of_arg (char *str);
int istheargincowt (char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char *split_the_str(char *str);
char	*arg_v_r(char *str);
char	**ft_split(char *s, char c);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *s1);
char *make_the_str_can_splited (char *str);
char *finale_char (char *str);
long long ft_atoi (char *str);

#endif