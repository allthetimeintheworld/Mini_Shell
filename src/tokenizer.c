/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j <j@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:58:52 by j                 #+#    #+#             */
/*   Updated: 2024/09/13 16:05:50 by j                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_shell.h"

int	is_operator(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

char	**tokenize(char *input)
{
	char	**tokens;
	int		i;
	int		j;
	int		token_index;
	int		in_quotes;
	char	*token;

	tokens = malloc(TOKEN_SIZE * sizeof(char *));
	if (!tokens)
		return (NULL);
	token = malloc(TOKEN_SIZE);
	i = 0;
	token_index = 0;
	j = 0;
	in_quotes = 0;
	while (input[i])
	{
		if (input[i] == '"')
			in_quotes = !in_quotes;
		else if (ft_isspace(input[i] && !in_quotes))
		{
			if (j > 0)
			{
				token[j] = '\0';
				tokens[token_index++] = ft_strdup(token);
				j = 0;
			}
		}
		else if (is_operator(input[i]) && !in_quotes)
		{
			if (j > 0)
			{
				token[j] = '\0';
				tokens[token_index++] = ft_strdup(token);
				j = 0;
			}
			token[j++] = input[i];
			token[j] = '\0';
			tokens[token_index++] = ft_strdup(token);
			j = 0;
		}
		else
			token[j++] = input[i];
		i++;
	}
	if (j > 0)
	{
		token[j] = '\0';
		tokens[token_index++] = ft_strdup(token);
	}
	tokens[token_index] = NULL;
	free(token);
	return (tokens);
}
