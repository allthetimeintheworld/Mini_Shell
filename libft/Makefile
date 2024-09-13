# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: j <j@student.42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 15:11:35 by jadyar            #+#    #+#              #
#    Updated: 2024/09/13 16:24:20 by j                ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = \
	ft_strlen.c \
	ft_isalpha.c \
	ft_isalnum.c \
	ft_isdigit.c \
	ft_isspace.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_strncmp.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_atoi.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strnstr.c \
	ft_bzero.c \
	ft_memset.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_itoa.c \
	ft_split.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c
BONUS_SRC = \
	ft_lstnew.c \
	ft_lstlast.c \
	ft_lstsize.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c
OBJ = $(SRC:%.c=obj/%.o)
BONUS_OBJ = $(BONUS_SRC:%.c=bonus_obj/%.o)

# Rule to make everything
all: obj $(NAME)

# Rule for bonus part
bonus: all bonus_obj $(BONUS_OBJ)
	ar rs $(NAME) $(BONUS_OBJ)

# Rule to make the object directory
obj:
	mkdir -p obj

# Rule to make the bonus object directory
bonus_obj:
	mkdir -p bonus_obj

# Rule to compile object files, with the object directory prefix
obj/%.o: %.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile bonus object files, with the bonus object directory prefix
bonus_obj/%.o: %.c | bonus_obj
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create static library
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

# Rule to clean object files
clean:
	rm -rf obj bonus_obj

# Rule to fully clean the directory of non-source files
fclean: clean
	rm -f $(NAME)

# Rule to re-make everything
re: fclean all

# Phony to prevent conflicts with files of the same name and to improve performance
.PHONY: all clean fclean re bonus