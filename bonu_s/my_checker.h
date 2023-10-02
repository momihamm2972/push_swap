/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:19:50 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/02 21:18:07 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_CHECKER_H
# define MY_CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct node
{
	int				data;
	int				indx_of_stack;
	int				length;
	int				are_in;
	int				moves_a;
	int				moves_b;
	int				total_moves;
	int				indx_of_node;
	int				position;
	struct node		*prev;
	struct node		*next;
}t_node;

/*#################### struct of parssing ##########################*/
typedef struct parss
{
	t_node	**stack_a;
	t_node	**stack_b;
	char	*arg1;
	char	*ptr;
	char	*ptr1;
	char	**arg2;
	int		*beforsorted;
	int		indx;
	int		indxarg;
	int		len_of_arr;
	int		sizeof_stack;
}t_parss;
/*##################################################################*/

t_node		*ft_lstnew(int content);
t_node		*min_value_in(t_node **stack);
t_node		*ft_lstlast(t_node **lst);
t_node		*before_the_last(t_node **stack);
t_node		*min_value_in(t_node **stack);
void		*my_calloc(size_t count, size_t size);
void		indxy_stack(t_node **stack);
void		rev_rotate(t_node **stack);
void		rrr(t_node **stack_a, t_node **stack_b);
void		excution(t_parss *excution);
void		swap_2_elements(t_node **stack);
void		ss(t_node **stack_a, t_node **stack_b);
void		push_to_stack(t_node **stack_0, t_node **stack_1);
void		rotate(t_node **stack);
void		rr(t_node **stack_a, t_node **stack_b);
void		*ft_calloc(size_t count, size_t size);
void		free_all(char **s, int ptrs);
void		ft_lstadd_back(t_node **lst, t_node *new);
void		make_args_usefull(t_parss *my_struct);
void		ft_free_a_stack(t_node **stack);
void		*ft_memcpy(void *to, const void *from, size_t len);
void		ft_double(t_node **stack, int num);
void		ft_are_sorted(t_node **stack);
void		ft_lstadd_front(t_node **lst, t_node *new);
char		*get_next_line(int fd);
char		*reading(int fd, char *buff_read);
char		*my_join(char *s1, char *s2);
char		*my_sawebstr(char *s, unsigned int start, size_t len);
char		*therestofline(char *str);
char		*ft_strjoin(char const *s1, char const *s2);
char		*arg_v_r(char *str);
char		*ft_substr(char *s, int start, int len);
char		**ft_split(char *s, char c);
char		*make_the_str_can_splited(char *str);
char		*ft_strdup(char *s1);
char		*finale_char(char *str);
int			isthereanewline(char *str);
int			ft_lenofstr(char *str, char c);
int			ft_strlen(char *str);
int			sipared_arg(char *str);
int			num_of_word(char *s, char c);
int			empty_arg(char *str);
int			ft_isdigit(char *str);
int			sing_of_arg(char *str);
int			error_msg(void);
int			istheargincowt(char *str);
int			ft_lstsize(t_node *lst);
int			sorted(t_node **stack);
int			only_sing(char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			is_sorted(t_node **stack);
size_t		contline(const char *s);
long long	ft_atoi(char *str);

#endif