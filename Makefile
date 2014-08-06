# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nquere <nquere@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/06/26 13:22:19 by nquere            #+#    #+#              #
#    Updated: 2014/06/26 14:36:24 by nquere           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBDIR = ./libft/
GET_NEXT_LINE_DIR = ./get_next_line/
NAME = lem-in
LIB = $(LIBDIR)libft.a
CC = gcc

SRC = lem_in.c\
	  $(GET_NEXT_LINE_DIR)get_next_line.c\
	  ft_list.c\
	  ft_list2.c\
	  ft_path.c\
	  ft_parsing.c\
	  ft_line.c\
	  ft_nmale.c\
	  ft_move.c
OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g -ggdb3
LFLAGS = -L$(LIBDIR)/ -lft

INCLUDES = $(LIBDIR)/includes
INCLUDES_GET = $(GET_NEXT_LINE_DIR)

all: $(NAME)

$(NAME): $(LIB) $(OBJ) lem_in.h
	@($(CC) $(CFLAGS) -I$(INCLUDES_GET) -I$(INCLUDES)\
		-o $(NAME) $(OBJ) $(LFLAGS))
	@echo "\033[35m$(NAME) created !\033[0m"

%.o: %.c
	@($(CC) -c $(CFLAGS) -o $@ $^ -I$(INCLUDES) -I$(INCLUDES_GET))

$(LIB): $(LIBDIR)
	@(cd $(LIBDIR) && $(MAKE))

clean:
	@(rm -f $(OBJ))
	@echo "\033[31mObject files deleted\033[0m"

fclean: clean
	@(cd $(LIBDIR) && $(MAKE) fclean)
	@(rm -f $(NAME))
	@echo "\033[31m$(NAME) deleted\033[0m"

re: fclean all

.PHONY: re fclean clean all
