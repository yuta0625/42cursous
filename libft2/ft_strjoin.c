/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:18:42 by yohya             #+#    #+#             */
/*   Updated: 2025/10/19 18:28:42 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static	int	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

static int	count_word(const char *s1, const char *s2)
{
	size_t	s1_count;
	size_t	s2_count;
	size_t	total;

	s1_count = ft_strlen(s1);
	s2_count = ft_strlen(s2);
	total = s1_count + s2_count;
	return (total);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (count_word(s1, s2) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
	{
		ret[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}

// int main(void)
// {
//     char *s1 = "hello";
//     char *s2 = "world";
//     char *temp = ft_strjoin(s1,s2);
//     printf("%s", temp);
//     free(temp);
//     return 0;
// }
