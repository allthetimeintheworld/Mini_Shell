/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:05:30 by j                 #+#    #+#             */
/*   Updated: 2024/09/24 14:23:01 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_shell.h"

int	main(int ac, char **av, char **envp)
{
	char	*input;
	char	**tokens;

	(void)ac;
	(void)av;
	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			break ;
		if (input[0] != '\0')
		{
			add_history(input);
			tokens = tokenize(input);
			if (tokens)
			{
				exec_cmd(tokens, envp);
				free(tokens);
			}
		}
		free(input);
	}
	return (0);
}
