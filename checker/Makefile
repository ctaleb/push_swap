# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 11:53:12 by ctaleb            #+#    #+#              #
#    Updated: 2021/06/14 10:33:27 by ctaleb           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

INCS_PATH = inc/
INCS = checker.h

SRC_DIR = src/
SRC = main.c \
		errors.c \
		get_next_line.c \
		get_next_line_utils.c \
		parsing_utils.c \
		list_utils.c \
		utils.c \
		init.c \
		parsing.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		swap.c
SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJS = $(SRCS:.c=.o)

NAME = checker

%.o: %.c $(INCS_PATH)$(INCS)
	$(CC) $(CFLAGS) -I $(INCS_PATH). -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ -I $(INCS_PATH). $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
