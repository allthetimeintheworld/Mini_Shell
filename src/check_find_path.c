/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_find_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:58:39 by jadyar            #+#    #+#             */
/*   Updated: 2024/09/26 16:37:59 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_shell.h"

char	*join_path_cmd(char *dir, char *cmd)
{
	char	*full_path;
	int		path_len;

	path_len = ft_strlen(dir) + ft_strlen(cmd) + 2;
	full_path = malloc(path_len);
	if (!full_path)
		return (NULL);
	ft_strcpy(full_path, dir);
	ft_strcat(full_path, "/");
	ft_strcat(full_path, cmd);
	return (full_path);
}

char	*find_command_in_path(char	*cmd)
{
	char	*path_env;
	char	*path_env_cpy;
	char	*dir;
	char	*full_path;

	path_env = getenv("PATH");
	if (!(path_env))
		return (NULL);
	path_env_cpy = ft_strdup(path_env);
	if (!(path_env_cpy))
		return (NULL);
	dir = ft_strtok(path_env_cpy, ":");
	while (dir)
	{
		full_path = join_path_cmd(dir, cmd);
		if (!full_path)
		{
			free(path_env_cpy);
			return (NULL);
		}
		if (access(full_path, F_OK) == 0)
		{
			free(path_env_cpy);
			return (full_path);
		}
		free(full_path);
		dir = ft_strtok(NULL, ":");
	}
	free(path_env_cpy);
	return (NULL);
}
