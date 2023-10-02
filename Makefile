# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 14:57:47 by momihamm          #+#    #+#              #
#    Updated: 2023/10/02 17:43:10 by momihamm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
FLAGS = -Wall -Werror -Wextra -g -fsanitize=address
FILES = manda/push_swap.c\
		manda/excution1.c\
		manda/excution2.c\
		manda/excution3.c\
		manda/excution4.c\
		manda/excution5.c\
		manda/excution6.c\
		manda/excution7.c\
		manda/excution8.c\
		manda/excution9.c\
		manda/excution10.c\
		manda/excution11.c\
		manda/parssing1.c\
		manda/parssing2.c\
		manda/parssing3.c\
		manda/parssing4.c\
		manda/parssing5.c\
		manda/operations.c\
		manda/operations1.c\
		manda/ft_linedlist.c\
		manda/utils0.c

OBJ = $(FILES:.c=.o)

all : $(NAME)

manda/%.o : manda/%.c manda/push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(FILES) $(FLAGS) -o $(NAME)

clean :
		@rm -f $(OBJ)

fclean : clean
		@rm -f $(NAME)

re : fclean all