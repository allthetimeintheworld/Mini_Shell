/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:41:57 by jadyar            #+#    #+#             */
/*   Updated: 2024/09/30 15:14:01 by dodordev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_shell.h"
#include "../../include/builtins.h"

#include "../../include/mini_shell.h"
#include "../../include/builtins.h"

static int	is_numeric(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	print_numeric_error(char *arg)
{
	ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
}

void	ft_exit(char **args)
{
	if (args[1])
	{
		if (!is_numeric(args[1]))
		{
			print_numeric_error(args[1]);
			exit(255);
		}
		if (args[2])
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
			exit(1);
		}
		exit(ft_atoi(args[1]));
	}
	else
		exit(0);
}


/*void	ft_exit(char **args)
{
	int	i;

	if (args[1])
	{
		i = 0;
		while (args[1][i])
		{
			if (ft_isdigit(args[1][i]) == 0)
			{
				ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
				ft_putstr_fd(args[1], STDERR_FILENO);
				ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
				exit(255);
			}
			i++;
		}
		if (args[2])
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
			exit(1);
		}
		else
			exit(ft_atoi(args[1]));
	}
	else
		exit(0);
}*/

/*void	ft_exit(char **args)
{
	//int	i;

	//i = 1;
	if (args[1])
	{
		if (ft_isdigit(args[1][0]) == 0)
		{
			ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
			ft_putstr_fd(args[1], STDERR_FILENO);
			ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
			exit(255);
		}
		else if (args[2])
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
			exit(1);
		}
		else
			exit(ft_atoi(args[1]));
	}
	else
		exit(0);
}*/
