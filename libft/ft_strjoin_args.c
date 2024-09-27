/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:07:23 by jadyar            #+#    #+#             */
/*   Updated: 2024/09/25 16:10:44 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_shell.h"

char	*ft_strjoin_args(char **av, int ac)
{
	char	*result;
	int		i;
	char	*tmp;

	i = 2;
	result = ft_strdup(av[1]);
	if (!result)
		return (NULL);
	while (i < ac)
	{
		tmp = ft_strjoin(result, " ");
		if (!tmp)
		{
			free(result);
			return (NULL);
		}
		free(result);
		result = ft_strjoin(tmp, av[i]);
		free(tmp);
		if (!result)
			return (NULL);
		i++;
	}
	return (result);
}
