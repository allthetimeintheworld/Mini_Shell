/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:41:57 by jadyar            #+#    #+#             */
/*   Updated: 2024/09/25 10:57:52 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_shell.h"
#include "../../include/builtins.h"

void	ft_exit(char **args)
{
	int	i;

	i = 1;
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
}
