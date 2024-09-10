/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:26:55 by jadyar            #+#    #+#             */
/*   Updated: 2023/11/21 17:14:48 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	trim_start;
	size_t	trim_end;
	char	*trimmed_string;

	if (!s1 || !set)
		return (NULL);
	trim_start = 0;
	trim_end = ft_strlen(s1);
	while (s1[trim_start] && ft_strchr(set, s1[trim_start]))
		trim_start++;
	while (trim_end >= trim_start && ft_strchr(set, s1[trim_end]))
		trim_end--;
	if (trim_start >= ft_strlen(s1))
		return (ft_strdup(""));
	trimmed_string = malloc(trim_end - trim_start + 2);
	if (!trimmed_string)
		return (NULL);
	ft_strlcpy(trimmed_string, s1 + trim_start, trim_end - trim_start + 2);
	trimmed_string[trim_end - trim_start + 1] = '\0';
	return (trimmed_string);
}
