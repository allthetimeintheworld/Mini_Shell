# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/05 14:34:50 by j                 #+#    #+#              #
#    Updated: 2024/09/25 11:00:08 by jadyar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

SRCS = src/main.c src/tokenizer.c src/exec.c src/check_find_path.c src/builtin/builtins.c src/utils.c src/parse.c  src/redirections.c src/signals.c src/builtin/ft_echo.c src/builtin/ft_cd.c src/builtin/ft_pwd.c src/builtin/ft_export.c src/builtin/ft_unset.c src/builtin/ft_env.c src/builtin/ft_exit.c
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g
LIBS = -lreadline

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(LIBFT)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

