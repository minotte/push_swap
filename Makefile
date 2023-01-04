# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nminotte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 16:03:52 by nminotte          #+#    #+#              #
#    Updated: 2022/12/21 10:46:24 by nminotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

SRC = push_swap.c \
	ft_error.c \
	normalize.c \
	ft_sort.c \
	ft_sort_sp.c \
	

OBJS = $(SRC:.c=.o) $(libft/:.c=.o)
 
CFLAGS = -Wall -Werror -Wextra

CC = clang

all : ${NAME}

$(NAME) : $(OBJS)
	@make -C ./libft
	@$(CC) -o $(NAME) $(OBJS) libft/libft.a

clean :
	@make clean -C ./libft
	@rm -rf $(OBJS)
	
fclean : clean
	@make fclean -C ./libft
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean re fclean
