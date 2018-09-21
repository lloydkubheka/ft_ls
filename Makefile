# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xkubheka <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/29 13:13:34 by xkubheka          #+#    #+#              #
#    Updated: 2018/09/10 12:49:47 by xkubheka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC =  main.c ft_ls.c  ls_d.c file_check.c

FLAGS = gcc -Wall -Werror -Wextra -o

all : $(NAME)

$(NAME):
	@echo "$(NAME)...success"
	@make -C libft/
	@$(FLAGS) $(NAME) $(SRC) -L libft/ -lft -I libft/includes -I includes

clean:
	@rm -rf $(NAME)

fclean:
	@make fclean -C libft/
	@rm -f $(NAME)

re : fclean all

norm:
	@nominette $(SRC) includes/ft_ls.h
