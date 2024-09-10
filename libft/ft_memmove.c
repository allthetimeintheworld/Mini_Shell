/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:29:08 by jadyar            #+#    #+#             */
/*   Updated: 2023/11/22 12:09:02 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dest;
	const char			*src1;

	dest = (unsigned char *)dst;
	src1 = (const char *)src;
	if (dest == NULL && src1 == NULL)
		return (NULL);
	if ((void *)dest <= (void *)src1)
	{
		while (n--)
			*dest++ = *src1++;
	}
	else
	{
		dest += n;
		src1 += n;
		while (n--)
			*(--dest) = *(--src1);
	}
	return (dst);
}
