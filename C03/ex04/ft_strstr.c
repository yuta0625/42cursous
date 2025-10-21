/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:16:45 by yohya             #+#    #+#             */
/*   Updated: 2025/10/18 14:23:08 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	str_count(char *str)
{
	int	j;

	j = 0;
	while (str[j] != '\0')
	{
		j++;
	}
	return (j);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	if (*str == '\0' && *to_find == '\0')
	{
		return (str);
	}
	while (*str != '\0')
	{
		i = 0;
		while (str[i] == to_find[i] && to_find[i] != '\0')
		{
			i++;
		}
		if (i == str_count(to_find))
		{
			return (str);
		}
		str++;
	}
	return (0);
}

int	main(void)
{
	char str[] = "str abcgnanka";
	char to_find[] = "ab";

	printf("%s\n", ft_strstr(str, to_find));
	char str1[] = "str abcgnanka";
	char to_find1[] = "ab";

	printf("%s\n", strstr(str1, to_find1));
}
