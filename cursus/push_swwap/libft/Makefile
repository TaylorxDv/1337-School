
Src = ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_atoi.c ft_memcmp.c ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_bzero.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putchar_fd.c 
SrcB = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
Cc = gcc
Flags = -Wall -Wextra -Werror
Name = libft.a

Obj = $(Src:.c=.o)
ObjB = $(SrcB:.c=.o)

$(Name): $(Obj)
	ar cr $(Name) $(Obj)

all: $(Name)

%.o: %.c libft.h
	$(Cc) $(Flags) -c $<

bonus: $(Obj) $(ObjB)
	ar cr $(Name) $(Obj) $(ObjB)

clean:
	rm -rf $(Obj) $(ObjB)

fclean: clean
	rm -rf $(Name)

re: fclean all

.PHONY: all bonus clean fclean re
