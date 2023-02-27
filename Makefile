# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 11:56:41 by lnaidu            #+#    #+#              #
#    Updated: 2023/02/27 10:26:39 by lnaidu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ./test.c ./command.c ./free.c

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m

all : $(NAME)

OBJS = ${SRC:.c=.o}

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(RED) Creating !"

$(NAME): $(OBJS)
	@make all bonus -C ./Libft
	@$(CC) $(OBJS) -o $(NAME) ./Libft/libft.a
	@echo "$(GREEN) Computing !"

clean :
	@rm -f $(OBJS)
	@echo "$(YELLOW) Deleting !"

fclean : clean
	@rm -f ./pipex
	@make fclean -C ./Libft

re : @fclean all

.PHONY: .c.o all clean fclean bonus re
