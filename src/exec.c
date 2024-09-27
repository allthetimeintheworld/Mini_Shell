/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:03:48 by j                 #+#    #+#             */
/*   Updated: 2024/09/27 16:10:21 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_shell.h"

/* void	exec_external(char **args, char **envp)
{
	char	*full_path;

	full_path = find_command_in_path(args[0]);
	if (full_path)
	{
		execve(full_path, args, envp);
		perror("execve");
		//exit(EXIT_FAILURE);
		printf ("minishell: %s: command not found dumdum\n", args[0]);
		return ;
	}
	else
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(args[0], STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		//exit(EXIT_FAILURE);
		printf ("minishell: %s: command not found dumdum2\n", args[0]);
		return ;
	}
}
Example of function needs to be changed to: a more functional use case-------tomorrow::

void	exec_external(char **args, char **envp)
{
	pid_t	pid;
		int status;
	pid_t	pid;
	char	*full_path;
		int status;

	pid = fork();
	if (pid == 0) // Child process
	{
		if (execve(args[0], args, envp) == -1)  // Execute external command
		{
			perror("minishell");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)  // Fork failed
	{
		perror("minishell");
	}
	else  // Parent process waits for the child
	{
		waitpid(pid, &status, 0);
	}
} */
void	exec_external(char **args, char **envp)
{
	pid_t	pid;
	char	*full_path;
	int		status;

	full_path = find_command_in_path(args[0]); // Search for the command in PATH
	if (full_path == NULL) // If command is not found, print error and return
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(args[0], STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		return ;
	}
	pid = fork(); // Fork a new process
	if (pid == 0) // In child process
	{
		execve(full_path, args, envp); // Execute the command
		perror("execve");              // If execve fails, print error
		exit(EXIT_FAILURE);            // Exit child process with failure code
	}
	else if (pid < 0) // Fork failed
	{
		perror("fork");
	}
	else // In parent process, wait for the child process to finish
	{
		waitpid(pid, &status, 0); // Wait for child to finish
	}
	free(full_path); // Free the memory allocated by find_command_in_path()
}

void	execute_pipe(char **left_cmd, char **right_cmd, char **envp)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO); // redirect stdout to pipe
		close(pipefd[0]);
		close(pipefd[1]);
		execve(left_cmd[0], left_cmd, envp);
		perror("execve (left cmd)");
		exit(EXIT_FAILURE);
	}
	else if (pid1 < 0)
	{
		perror("fork (left cmd)");
		exit(EXIT_FAILURE);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		execve(right_cmd[0], right_cmd, envp);
		perror("execve (right cmd)");
		exit(EXIT_FAILURE);
	}
	else if (pid2 < 0)
	{
		perror("fork (right cmd)");
		exit(EXIT_FAILURE);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

void	exec_cmd(char **args, char **envp)
{
	int		i;
	int		j;
	char	**left_cmd;
	char	**right_cmd;

	i = 0;
	while (args[i] && ft_strcmp(args[i], "|"))
		i++;
	left_cmd = malloc(sizeof(char *) * (i + 1));
	if (!left_cmd)
	{
		perror("malloc");
		return ;
	}
	j = 0;
	while (j < i)
	{
		left_cmd[j] = ft_strdup(args[j]);
		j++;
	}
	left_cmd[j] = NULL;
	if (args[i] && ft_strcmp(args[i], "|") == 0)
	{
		i++;
		right_cmd = malloc(sizeof(char *) * (count_args(args) - i + 1));
		if (!right_cmd)
			return ;
				// perror and free_token probs to  .. use exit(EXIT_FAILURE)?
		j = 0;
		while (args[i])
		{
			right_cmd[j] = ft_strdup(args[i]); // if(!right_cmd[j]) return maybe
			i++;
			j++;
		}
		right_cmd[j] = NULL;
		execute_pipe(left_cmd, right_cmd, envp);
		free_tokens(right_cmd);
	}
	else
		exec_external(left_cmd, envp);
	free_tokens(left_cmd);
}
