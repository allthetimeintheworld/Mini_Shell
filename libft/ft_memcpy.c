/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:19:34 by jadyar            #+#    #+#             */
/*   Updated: 2023/11/22 12:13:58 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dst;
	const char	*src1;

	dst = (char *)dest;
	src1 = (const char *)src;
	if (dest == NULL && src1 == NULL)
		return (NULL);
	while (n--)
	{
		dst[n] = src1[n];
	}
	return (dest);
}
