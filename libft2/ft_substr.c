/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:49:26 by yohya             #+#    #+#             */
/*   Updated: 2025/10/21 19:42:41 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_start_tolong(void)
{
	char	*empty;

	empty = (char *)malloc(1);
	if (empty)
		empty[0] = '\0';
	return (empty);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_start_tolong());
	if (s_len - start < len)
		len = s_len - start;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

// int main(void)
// {
// 	char *s = "abede";
// 	unsigned int start = 10;
// 	size_t	len = 8;
// 	printf("%s", ft_substr(s, start, 8));
// }
