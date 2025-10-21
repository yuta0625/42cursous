/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:47:45 by yohya             #+#    #+#             */
/*   Updated: 2025/09/18 18:06:18 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	while (src[i])
		i++;
	ret = (char *)malloc(sizeof(char) *(i + 1));
	if (!ret)
		return (NULL);
	j = 0;
	while (j < i)
	{
		ret[j] = src[j];
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

// int main(void)
// {
// 	char *src = "hello";
// 	printf("%s", ft_strdup(src));
// }
