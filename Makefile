# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 11:56:41 by lnaidu            #+#    #+#              #
#    Updated: 2023/03/07 15:59:39 by lnaidu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAMEBONUS = pipex_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC = ./mandatory/main.c ./mandatory/command.c ./mandatory/free.c ./mandatory/process.c ./mandatory/error.c
SRC_BONUS = ./bonus/main_bonus.c ./bonus/main_herdoc.c ./bonus/command_bonus.c ./bonus/err_bonus.c ./bonus/free_bonus.c ./bonus/process_bonus.c ./bonus/heredoc.c
#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m


OBJS = ${SRC:.c=.o}
OBJS_BONUS = ${SRC_BONUS:.c=.o}

$(NAME): $(OBJS)
	@make all -C ./Libft
	@$(CC) $(CFLAGS) ${OBJS} ./Libft/libft.a -o $(NAME)
	@echo "$(GREEN) Computing !"

all : $(NAME)

bonus : $(OBJS_BONUS)
	@make all -C ./Libft
	@$(CC) $(CFLAGS) ${OBJS_BONUS} ./Libft/libft.a -o $(NAMEBONUS)
	@echo "$(GREEN) Computing !"

clean :
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)
	@echo "$(YELLOW) Deleting !"

fclean : clean
	@rm -f ./pipex
	@rm -f ./pipex_bonus
	@make fclean -C ./Libft

re : fclean all

.PHONY: all clean fclean bonus re


	


