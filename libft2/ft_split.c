/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:22:05 by yohya             #+#    #+#             */
/*   Updated: 2025/10/24 15:04:54 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		if ((s[i] != c) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static char	*malloc_dup(const char *start, size_t len)
{
	char	*temp;
	size_t	i;

	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (i < len)
	{
		temp[i] = start[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

static void	free_all(char **arr, size_t n)
{
	while (n > 0)
	{
		free(arr[n]);
		n--;
	}
	free(arr);
}

static	char	*next_word(const char **ps, char c)
{
	const char	*s1;
	const char	*start;

	s1 = *ps;
	while (*s1 && *s1 == c)
		s1++;
	start = s1;
	while (*s1 && *s1 != c)
		s1++;
	*ps = s1;
	return (malloc_dup(start, (size_t)(s1 - start)));
}

char	**ft_split(const char *s, char c)
{
	char			**ret;
	size_t			word;
	size_t			i;

	if (!s)
		return (NULL);
	word = count_word(s, c);
	ret = (char **)malloc(sizeof(char *) * (word + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < word)
	{
		ret[i] = next_word(&s, c);
		if (!ret[i])
		{
			free_all(ret, i);
			return (NULL);
		}
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

// int	main(void)
// {
// 	char	*s = "42tokyo hello";
// 	char	c = ' ';
// 	char	**arr = ft_split(s, c);
// 	for (size_t i = 0; arr[i]; i++)
// 		printf("%s\n", arr[i]);
// 	free(arr);
// 	return (0);
// }
