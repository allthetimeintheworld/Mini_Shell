# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: j <j@student.42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/05 14:34:50 by j                 #+#    #+#              #
#    Updated: 2024/09/13 15:44:08 by j                ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

# Liste des fichiers sources et objets
SRCS = src/main.c src/tokenizer.c # Ajoute d'autres fichiers .c au besoin
OBJS = $(SRCS:.c=.o)

# Variables pour la compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = -lreadline

# Répertoires et fichiers de la libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Règle all
all: $(LIBFT) $(NAME)

# Compilation de la libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Compilation de Minishell
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(LIBFT)

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

# Nettoyage complet
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

# Recompilation complète
re: fclean all

