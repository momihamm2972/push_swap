# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 14:57:47 by momihamm          #+#    #+#              #
#    Updated: 2023/06/19 00:39:54 by momihamm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
FLAGS = -Wall -Werror -Wextra
FILES = push_swap.c\
		excution0.c\
		excution1.c\
		excution2.c\
		excution3.c\
		excution4.c\
		excution5.c\
		excution6.c\
		parssing1.c\
		parssing2.c\
		parssing3.c\
		parssing4.c\
		parssing5.c\
		parssing6.c\
		operations.c\
		operations1.c\
		ft_linedlist.c\
		utils0.c

OBJ = $(FILES:.c=.o)

all : $(NAME)

%.o : %.c push_swap.h
	$(CC) $(FLAGS) -c $<

$(NAME) : $(OBJ)
	$(CC) $(FILES) $(FLAGS) -o $(NAME)

clean :
		@rm -f $(OBJ)

fclean : clean
		@rm -f $(NAME)

re : fclean all