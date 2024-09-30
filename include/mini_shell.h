/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:56:11 by j                 #+#    #+#             */
/*   Updated: 2024/09/30 14:36:18 by dodordev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include <fcntl.h>

# define TOKEN_SIZE 1024
# define TOKEN_DELIM " \t\r\n\a"

int		main(int ac, char **av, char **envp);
void	exec_external(char **args, char **envp);
char	*find_command_in_path(char *command);
void	setup_signals(void);
void	sigint_handler(int sig);
int		is_operator(char c);
char	**tokenize(char *input);
void	exec_cmd(char **args, char **envp);
void	execute_pipe(char **left_cmd, char **right_cmd, char **envp);
void	free_tokens(char **tokens);
int		count_args(char **args);
#endif