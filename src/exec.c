/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j <j@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:03:48 by j                 #+#    #+#             */
/*   Updated: 2024/09/18 16:17:26 by j                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_shell.h"

void	exec_external(char **args)
{
	pid_t	pid;
	int		status;
	
	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		perror("fork");
	else
		waitpid(pid, &status, 0);
}
void	execute_pipe(char **left_cmd, char **right_cmd)
{
	int pipefd[2];
	pid_t pid1;
	pid_t pid2;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO);// redirect stdout to pipe
		close(pipefd[0]);//close read end
		close(pipefd[1]);//close write end
		execve(left_cmd[0], left_cmd, NULL);// execute left command	
	//	exec_external(left_cmd);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else if (pid1 < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(pipefd[0], STDIN_FILENO);// redirect stdin to pipe
		close(pipefd[0]);//close read end
		close(pipefd[1]);//close write end
		execve(right_cmd[0], right_cmd, NULL);// execute right command
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else if (pid2 < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	close(pipefd[0]);//close write end
	close(pipefd[1]);//close write end
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
void	exec_cmd(char **args)
{
	int i;
	int j;
	char **left_cmd;
	char **right_cmd;

	i = 0;
	j = 0;
	while (args[i] && ft_strcmp(args[i], "|"))
		i++;
	left_cmd = malloc(sizeof(char *) * (i + 1));
	if (!left_cmd)
		exit(EXIT_FAILURE);
	while (j < i)
	{
		left_cmd[j] = ft_strdup(args[j]);
		j++;
	}
	left_cmd[j] = NULL;
	if (args[i])
	{
		i++;
		right_cmd = malloc(sizeof(char *) * (count_args(args) - i + 1));
		if (!right_cmd)
			exit(EXIT_FAILURE);
		j = 0;
		while (args[i])
		{
			right_cmd[j] = ft_strdup(args[i]);
			i++;
			j++;
		}
		right_cmd[j] = NULL;
		execute_pipe(left_cmd, right_cmd);
	}
	else
		exec_external(left_cmd);
}
