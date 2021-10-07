# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 09:34:27 by ctaleb            #+#    #+#              #
#    Updated: 2021/06/14 10:33:21 by ctaleb           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

INCS_PATH = inc/
INCS = push_swap.h

SRC_DIR = ./src/
SRC = main.c \
		errors.c \
		init.c \
		list_utils.c \
		chunk_utils.c \
		parsing_utils.c \
		swap.c \
		push.c \
		rotate.c \
		reverse_rotate.c \
		parsing.c \
		sort_inf.c \
		sort_short_3.c \
		sort_short_5.c \
		sort_long_100.c \
		push_back.c \
		sort_long_500.c \
		utils.c
SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJS = $(SRCS:.c=.o)

NAME = push_swap

%.o: %.c $(INCS_PATH)$(INCS)
	$(CC) $(CFLAGS) -I $(INCS_PATH). -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ -I $(INCS_PATH). $(OBJS)

bonus: checker_

checker_:
	make -C checker/

clean:
	$(RM) $(OBJS)
	make -C checker/ clean

fclean: clean
	$(RM) $(NAME)
	make -C checker/ fclean

re: fclean all

.PHONY: all bonus clean fclean re