# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarzoug <amarzoug@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 17:34:59 by amarzoug          #+#    #+#              #
#    Updated: 2022/06/20 17:41:02 by amarzoug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  rules/rules.c rules/rules_2.c rules/rules_3.c algo.c \
		ft_checking.c ft_fix.c indexing.c lst_utiles.c markup.c \
		send_to_b.c
SRCB = checker.c
SRCM = push_swap.c
NAME = push_swap
NAMEB = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(SRCM) $(SRCS) libft/libft.a push_swap.h
	$(CC) $(CFLAGS) -o $(NAME) $(SRCM) $(SRCS) libft/libft.a

$(NAMEB): $(SRCB) $(SRCS) Libft/libft.a push_swap.h
	$(CC) $(CFLAGS) -o $(NAMEB) $(SRCB) $(SRCS) libft/libft.a

.PHONY: all re clean fclean bonus

libft/libft.a:
	make -C Libft all

all: $(NAME)

bonus: $(NAMEB)

clean:
	make -C Libft clean

fclean:
	make -C Libft fclean
	rm -rf $(NAME) $(NAMEB)

re: fclean all

