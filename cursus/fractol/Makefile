# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 11:42:56 by schahid           #+#    #+#              #
#    Updated: 2022/04/28 00:51:09 by ariahi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Programs
NAME= fractol
SRC= *.c
CC= gcc
HEADERS= fractol.h
MINILIBX= /usr/local/include
CFLAGS=  -Wall -Wextra -Werror
OBJ=$(patsubst %.c,%.o,$(SRC))

#Text
END=$'\x1b[0m
BOLD=$'\x1b[1m
UNDER=$'\x1b[4m
REV=$'\x1b[7m

#Colors
GREY=$'\x1b[30m
RED=$'\x1b[31m
GREEN=$'\x1b[32m
YELLOW=$'\x1b[33m
BLUE=$'\x1b[34m
PURPLE=$'\x1b[35m
CYAN=$'\x1b[36m
WHITE=$'\x1b[37m

all : $(NAME)

$(NAME): $(OBJ) fractol.h
		@$(CC) $(CFLAGS) $(SRC) -o $(NAME) -I $(HEADERS) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
		@echo "$(BOLD)$(WHITE)Fract-ol has been compiled successfully$(END)"
		@echo "$(BOLD)$(GREY)\nType ./fractol to launch the program\n$(END)"
		@echo "$(BOLD)$(GREY)\nType ./fractol JC to launch the julia set values\n$(END)"

$(OBJ): 
		@$(CC) $(FLAGS) -c $(SRC)

$(MINILIBX):
		make minilibx

clean :
		@-rm -f $(OBJ)
		@echo "$(BOLD)$(CYAN)Object files has been cleaned successfully$(END)"

fclean : clean
		@-rm -f $(NAME)
		@echo "$(BOLD)$(GREEN)fractol has been cleaned successfully$(END)"

re : fclean all

.PHONY : clean fclean re
