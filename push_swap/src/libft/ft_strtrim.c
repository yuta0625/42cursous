/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:38:58 by yohya             #+#    #+#             */
/*   Updated: 2025/10/24 15:03:37 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	size_t	i;
	char	*ret;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && trim_count(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && trim_count(set, s1[end - 1]))
		end--;
	ret = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < (end - start))
	{
		ret[i] = s1[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

// int	main(void)
// {
// 	char	*s1 = "";
// 	char	*set = "hello";
// 	printf("%s", ft_strtrim(s1, set));
// }
