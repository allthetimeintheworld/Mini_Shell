# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: j <j@student.42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/05 14:34:50 by j                 #+#    #+#              #
#    Updated: 2024/09/18 16:10:50 by j                ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

SRCS = src/main.c src/tokenizer.c src/exec.c src/builtins.c src/utils.c src/parse.c  src/redirections.c src/signals.c 
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

