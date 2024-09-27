/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:05:30 by j                 #+#    #+#             */
/*   Updated: 2024/09/26 16:53:14 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_shell.h"

int	main(int ac, char **av, char **envp)
{
	char	*input;
	char	**tokens;

	if (ac > 1) //dealing with batch mode
	{
		input = ft_strjoin_args(av, ac);
		if (!input)
			return (1);
		tokens = tokenize(input);
		if (tokens && tokens[0])
		{
			exec_cmd(tokens, envp);
			free_tokens(tokens);
		}
		free(input);
	}
	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			break ;
		if (ft_strlen(input) > 0)
		{
			add_history(input);
			tokens = tokenize(input);
			if (!tokens)
			{
				free(input);
				continue ;
			}
			if (tokens && tokens[0])
			{
				exec_cmd(tokens, envp);
			}
			free_tokens(tokens);
		}
		free(input);
	}
	return (0);
}
