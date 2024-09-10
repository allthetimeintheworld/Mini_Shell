/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:14:55 by jadyar            #+#    #+#             */
/*   Updated: 2023/11/22 10:01:24 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	n;

	n = (unsigned char)c;
	i = (ft_strlen(s));
	while (i + 1)
	{
		if (s[i] == n)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}
