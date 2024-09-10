/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j <j@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:03:48 by j                 #+#    #+#             */
/*   Updated: 2024/09/10 17:53:01 by j                ###   ########.fr       */
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
		else if (pid < 0)
			perror("fork");
		else
			waitpid(pid, &status, 0);
	}
}
