/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:44:43 by jadyar            #+#    #+#             */
/*   Updated: 2023/11/21 17:56:07 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	n;

	n = (unsigned char)c;
	while (*s)
	{
		if (*s == n)
			return ((char *)s);
		s++;
	}
	if (n == '\0')
		return ((char *)s);
	return (0);
}
