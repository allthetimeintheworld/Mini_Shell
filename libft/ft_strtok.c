/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:40:53 by jadyar            #+#    #+#             */
/*   Updated: 2024/09/24 13:41:16 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*last = NULL;
	char		*token;
	int			i;

	if (str == NULL && last == NULL)
		return (NULL);
	if (str != NULL)
		last = str;
	i = 0;
	while (last[i] != '\0' && !ft_strchr(delim, last[i]))
		i++;
	if (last[i] == '\0')
	{
		token = last;
		last = NULL;
	}
	else
	{
		last[i] = '\0';
		token = last;
		last += i + 1;
	}
	return (token);
}
