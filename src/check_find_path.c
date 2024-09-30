/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_find_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:58:39 by jadyar            #+#    #+#             */
/*   Updated: 2024/09/30 14:16:53 by dodordev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_shell.h"

/*char	*join_path_cmd(char *dir, char *cmd)
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
}*/

// Function to get a copy of the PATH environment variable
static char	*get_path_env(void)
{
	char	*path_env;

	path_env = getenv("PATH");
	if (!path_env)
		return (NULL);
	return (ft_strdup(path_env));
}

// Function to join the directory path and command
static char	*join_path_cmd(char *dir, char *cmd)
{
	char	*full_path;
	char	*temp;

	temp = ft_strjoin(dir, "/");
	if (!temp)
		return (NULL);
	full_path = ft_strjoin(temp, cmd);
	free(temp);
	if (!full_path)
		return (NULL);
	return (full_path);
}

// Function to check if the command exists in the current directory
static char	*check_directory(char *dir, char *cmd)
{
	char	*full_path;

	full_path = join_path_cmd(dir, cmd);
	if (!full_path)
		return (NULL);
	if (access(full_path, F_OK) == 0)
		return (full_path);
	free(full_path);
	return (NULL);
}

// Main function to find the command in the PATH
char	*find_command_in_path(char *cmd)
{
	char	*path_env_cpy;
	char	*dir;
	char	*full_path;

	path_env_cpy = get_path_env();
	if (!path_env_cpy)
		return (NULL);
	dir = ft_strtok(path_env_cpy, ":");
	while (dir)
	{
		full_path = check_directory(dir, cmd);
		if (full_path)
		{
			free(path_env_cpy);
			return (full_path);
		}
		dir = ft_strtok(NULL, ":");
	}
	free(path_env_cpy);
	return (NULL);
}


/*char	*find_command_in_path(char	*cmd)
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
}*/
