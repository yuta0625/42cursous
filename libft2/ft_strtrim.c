/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:38:58 by yohya             #+#    #+#             */
/*   Updated: 2025/10/23 16:40:52 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

static int	trim_count(const char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	total;
	size_t	i;
	char	*ret;

	start = 0;
	while (s1[start] && trim_count(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && trim_count(set, s1[end - 1]))
		end--;
	total = end - start;
	ret = (char *)malloc(sizeof(char) * (total + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < total)
	{
		ret[i] = s1[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

// int	main(void)
// {
// 	char	*s1 = "42tokyo";
// 	char	*set = "4ok";
// 	printf("%s", ft_strtrim(s1, set));
// }
