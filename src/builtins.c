/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:02:57 by j                 #+#    #+#             */
/*   Updated: 2024/09/24 14:31:24 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_shell.h"
#include "../include/builtins.h"
#include "../libft/libft.h"

int	is_builtin(char *cmd)
{
	return (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "cd")
		|| !ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "unset") || !ft_strcmp(cmd, "env")
		|| !ft_strcmp(cmd, "exit"));
}

void	execute_builtin(char **args)
{
	if (!ft_strcmp(args[0], "cd"))
		ft_cd(args);
	else if (!ft_strcmp(args[0], "pwd"))
		ft_pwd();
	else if (!ft_strcmp(args[0], "echo"))
		ft_echo(args);
/* 	else if (!ft_strcmp(args[0], "exit"))
		ft_exit(args);
	else if (!ft_strcmp(args[0], "env"))
		ft_env();
	else if (!ft_strcmp(args[0], "export"))
		ft_export(args);
	else if (!ft_strcmp(args[0], "unset"))
		ft_unset(args); */
}

void	execute_cmd(char **args)
{
	if (args[0] == NULL)
		return ;
	if (is_builtin(args[0]))
		execute_builtin(args);
	else
		exec_external(args, NULL);
}

void	ft_cd(char **args)
{
	if (args[1] == NULL)
	{
		if (chdir(getenv("HOME")) != 0)
			perror("minishell");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			ft_putstr_fd("minishell: cd: ", 2);
			ft_putstr_fd(args[1], 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			//fd Free?
		}
	}
}

void	ft_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	printf("%s\n", cwd);
	free(cwd);
}

void	ft_echo(char **args)
{
	int i;
	int newline;

	newline = 1;
	i = 1;
	if (args[1] && !ft_strcmp(args[1], "-n"))
	{
		newline = 0;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (newline)
		printf("\n");
}	