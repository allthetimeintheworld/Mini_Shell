/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:35:51 by jadyar            #+#    #+#             */
/*   Updated: 2023/11/22 13:02:31 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	char	*bptr;
	char	*lptr;

	if (!*little)
		return ((char *)big);
	while (len-- && *big)
	{
		if (*big == *little)
		{
			i = len;
			bptr = ((char *)big + 1);
			lptr = ((char *)little + 1);
			while (i-- && *bptr && *lptr && *lptr == *bptr)
			{
				++lptr;
				++bptr;
			}
			if (*lptr == '\0')
				return ((char *)big);
		}
		++big;
	}
	return (NULL);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char *big = "Hello, world!";
	char *little = "man world";
	size_t len = 10;

	char *result = ft_strnstr(big, little, len);
	if (result)
	{
		printf("The substring '%s' was found at index %ld in the string '%s'\n",
			little, result - big, big);
	}
	else
	{
		printf("The substring '%s' was not found in the string '%s'\n", little,
			big);
	}
	return (0);
} */