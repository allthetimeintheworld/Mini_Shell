/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:03:35 by jadyar            #+#    #+#             */
/*   Updated: 2023/11/22 16:29:35 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sub_len;
	char	*substring;
	char	*empty_str;

	sub_len = len;
	if (start >= ft_strlen(s))
	{
		empty_str = (char *)malloc(1);
		if (empty_str == NULL)
			return (NULL);
		empty_str[0] = '\0';
		return (empty_str);
	}
	if (start + sub_len > ft_strlen(s))
	{
		sub_len = ft_strlen(s) - start;
	}
	substring = (char *)malloc((sub_len + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	ft_strlcpy(substring, s + start, sub_len + 1);
	substring[sub_len] = '\0';
	return (substring);
}
/*
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

// Assuming ft_strlen and ft_strncpy are defined elsewhere in your code

int	main(void)
{
	const char	*input1 = "Hello, World!";
	char		*result1;
	const char	*input2 = "Testing";
	char		*result2;
	const char	*input3 = "123456789";
	char		*result3;
	const char	*input4 = "Short";
	char		*result4;
	const char	*input5 = "Hello";
	char		*result5;

	// Test case 1: Basic test
	result1 = ft_substr(input1, 7, 5);
	printf("Test Case 1: %s\n", result1);
	free(result1);
	// Test case 2: Extracting a substring from the beginning
	result2 = ft_substr(input2, 0, 4);
	printf("Test Case 2: %s\n", result2);
	free(result2);
	// Test case 3: Extracting a substring from the middle
	result3 = ft_substr(input3, 3, 4);
	printf("Test Case 3: %s\n", result3);
	free(result3);
	// Test case 4: Extracting a substring that exceeds the string length
	result4 = ft_substr(input4, 0, 10);
	printf("Test Case 4: %s\n", result4);
	free(result4);
	// Test case 5: Starting index beyond string length
	result5 = ft_substr(input5, 10, 3);
	printf("Test Case 5: %s\n", result5);
	free(result5);
	return (0);
}
*/
