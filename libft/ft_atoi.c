/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j <j@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:35:45 by jadyar            #+#    #+#             */
/*   Updated: 2024/09/13 16:15:01 by j                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* static int	ft_isspace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
} */

int	ft_atoi(const char *nptr)
{
	int			sign;
	long long	nbr;

	sign = 1;
	nbr = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
		nbr = nbr * 10 + *nptr++ - '0';
	return (nbr * sign);
}
/*int	ft_atoi(const char *nptr)
{
	int			i;
	long long	nbr;
	int			sign;
    const char *str1 = "-2147483648";
    const char *str2 = "-6789";
    const char *str3 = "  +42";
    const char *str4 = "   -123abc";

	i = 0;
	nbr = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] == 9 && nptr[i] == 13))
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + nptr[i] - '0';
		i++;
	}
	return (nbr * sign);
}
#include <stdio.h>
int	main(void) {
    printf("String: %s, Integer: %d\n", str1, ft_atoi(str1));
    printf("String: %s, Integer: %d\n", str2, ft_atoi(str2));
    printf("String: %s, Integer: %d\n", str3, ft_atoi(str3));
    printf("String: %s, Integer: %d\n", str4, ft_atoi(str4));
    return (0);
}*/