/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:02:57 by j                 #+#    #+#             */
/*   Updated: 2024/09/25 12:33:39 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_shell.h"
#include "../../include/builtins.h"
#include "../../libft/libft.h"

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
 	else if (!ft_strcmp(args[0], "exit"))
		ft_exit(args);
	//else if (!ft_strcmp(args[0], "env"))
	//	ft_env();
	else if (!ft_strcmp(args[0], "export"))
		ft_export(args);
	else if (!ft_strcmp(args[0], "unset"))
		ft_unset(args);
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
