/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j <j@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:05:30 by j                 #+#    #+#             */
/*   Updated: 2024/09/18 15:54:51 by j                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/mini_shell.h"

int main(void)
{
	char *input;
	char **tokens;
	
	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			break ;
		if (input[0] != '\0')
		{
			add_history(input);
		//printf("Your input was %s\n", input);
			tokens = tokenize(input);
			if (tokens)
			{
				exec_cmd(tokens);
				free(tokens);
			}
		}
		free(input);
	}
	return (0);
}