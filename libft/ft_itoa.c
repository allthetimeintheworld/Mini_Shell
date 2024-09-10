/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:04:06 by jadyar            #+#    #+#             */
/*   Updated: 2023/11/22 10:08:22 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_number_length(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		nlen;
	char	*arr;
	long	nbr;

	nbr = n;
	nlen = get_number_length(nbr);
	arr = malloc(nlen + 1);
	if (!arr)
		return (0);
	arr[nlen--] = '\0';
	if (nbr < 0)
	{
		nbr = -nbr;
		arr[0] = '-';
	}
	while (nbr >= 10)
	{
		arr[nlen--] = nbr % 10 + '0';
		nbr /= 10;
	}
	arr[nlen--] = nbr % 10 + '0';
	return (arr);
}
