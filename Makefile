# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 14:57:47 by momihamm          #+#    #+#              #
#    Updated: 2023/10/05 00:17:45 by momihamm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = my_checker
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
BONUS_FILES = bonu_s/bonus_utils.c \
			  bonu_s/bonusparss0.c \
			  bonu_s/bonusparss1.c \
			  bonu_s/bonusparss2.c \
			  bonu_s/bonusparss3.c \
			  bonu_s/bonusparss4.c \
			  bonu_s/bonusparss5.c \
			  bonu_s/bonusparss6.c \
			  bonu_s/get_next_line.c \
			  bonu_s/get_next_line_utils.c \
			  bonu_s/linked_bonus0.c \
			  bonu_s/linked_bonus1.c \
			  bonu_s/linked_bonus2.c \
			  bonu_s/my_checker.c \

OBJ = $(FILES:.c=.o)

BONUS_OBJ = $(BONUS_FILES:.c=.o)

all : $(NAME)

manda/%.o : manda/%.c manda/push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(FILES) $(FLAGS) -o $(NAME)

bonus : $(BONUS_NAME)

bonu_s/%.o : bonu_s/%.c bonu_s/my_checker.h
	$(CC) $(FLAGS) -c $< -o $@

$(BONUS_NAME) : $(BONUS_OBJ)
	$(CC) $(BONUS_FILES) $(FLAGS) -o $(BONUS_NAME)

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all

clean_bonus :
			  @rm -f $(BONUS_OBJ)

fclean_bonus : clean_bonus
			  @rm -f $(BONUS_NAME)

re_bonus : fclean_bonus bonus