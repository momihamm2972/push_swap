/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:55:00 by momihamm          #+#    #+#             */
/*   Updated: 2023/09/29 02:33:20 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
t_node		*ft_lstlast(t_node **lst);
t_node		*before_the_last(t_node **stack);
t_node  *at_least (t_node **stack);
t_node  *second_node (t_node **stack, int info);
t_node  *next_of_num (t_node **stack, int info);
t_node  *min_instractions(t_node **stack);
t_node  *next_of_num_sicondo (t_node **stack, int info);
t_node *min_value_in (t_node **stack);
void		push_to_stack(t_node **stack_0, t_node **stack_1, int delta);
void		swap_2_elements(t_node **stack, int delta);
void		print_nodes(t_node **stack);
void		rotate(t_node **stack, int delta);
void		rev_rotate(t_node **stack, int delta);
void		rrr(t_node **stack_a, t_node **stack_b);
void		rr(t_node **stack_a, t_node **stack_b);
void		ss(t_node **stack_a, t_node **stack_b);
void		ft_lstadd_back(t_node **lst, t_node *new);
void		ft_lstadd_front(t_node **lst, t_node *new);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memcpy(void *to, const void *from, size_t len);
void		make_args_usefull(t_parss *my_struct);
void		ft_free_a_stack(t_node **stack);
void		ft_double(t_node **stack, int num);
void		make_the_length_one(t_parss *length);
void		lis(t_parss *lewandowski);
void		print_lis(t_node **stacka);
void		print_the_lis(t_node **stack, int length);
void		check_the_lis_are_in(t_node **stack, int length);
void		make_the_lis_in_a(t_parss *fcbayern);
void		make_a_in_oredre(t_node **stack);
void		ft_are_sorted(t_node **stack);
void		indxy_stack(t_node **stack);
void		if_min_max_in_b (t_parss *azalim);
void		an_node (t_node **stack, int info);
void   		cont_the_best_b (t_node **stack);
void		make_top (t_node **stack, int info);
void	make_it_top (t_parss *munchen, int info);
void	best_move_in_b (t_parss *djaja);
void	best_move_in_a (t_parss *jwan);
void	total_of_a_b (t_parss *tamawayet);
void	rev_or (t_node **stack);
void	keep_it (t_parss *speed);
void    ft_all_most (t_parss *sane);
void    node_of_top (t_node **stack, int info, int name_of_inst, int type_of);
void    make_money_a(t_node **stack, t_node *place, int info);
void    make_money_b(t_node **stack, t_node *place, int info);
int			sipared_arg(char *str);
int			ft_lstsize(t_node *head);
int			ft_strlen(char *str);
int			num_of_word(char *s, char c);
int			ft_isalpha(int c);
int			ft_isdigit(char *str);
int			ft_isdigit_atoi(int c);
int			error_msg(void);
int			empty_arg(char *str);
int			sing_of_arg(char *str);
int			istheargincowt(char *str);
int			only_sing(char *str);
int			find_the_big_length(t_node **stacka);
int			check_if_lis_in_a(t_node **stack);
int			min_value(t_node **stack);
int	big_value(t_node **stack);
int	how_may_move (t_parss *kane, int info);
int	big_than (t_node **stack, int info);
int	is_it (t_node **stack, int info, int min);
// int min_instractions(t_node **stack);
char		*ft_strjoin(char const *s1, char const *s2);
char		*arg_v_r(char *str);
char		**ft_split(char *s, char c);
char		*ft_substr(char *s, int start, int len);
char		*ft_strdup(char *s1);
char		*make_the_str_can_splited(char *str);
char		*finale_char(char *str);
long long	ft_atoi(char *str);

#endif