/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:10:02 by yohya             #+#    #+#             */
/*   Updated: 2025/10/20 11:48:16 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (!is_sep(str[i], charset) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_sep(str[i], charset))
		{
			in_word = 0;
		}
		i++;
	}
	return (count);
}

char	*ft_dupstr(char *start, int len)
{
	char	*temp;
	int		i;

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

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		words;
	int		i;
	int		len;
	char	*start;

	words = count_word(str, charset);
	ret = (char **)malloc(sizeof(char *) * (words + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (!is_sep(*str, charset))
		{
			start = str;
			len = 0;
			while (*str && !is_sep(*str, charset))
			{
				str++;
				len++;
			}
			ret[i++] = ft_dupstr(start, len);
		}
		str++;
	}
	ret[i] = NULL;
	return (ret);
}

int	main(void)
{
	char str[] = "42tokyo;;,yohya,helloworld";
	char *charset = ",";
	char **arr = ft_split(str, charset);
	for(int i = 0; arr[i]; i++)
	printf("%s\n", arr[i]);
	free(arr);
	return (0);
}
