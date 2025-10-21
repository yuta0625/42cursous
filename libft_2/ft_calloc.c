/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:12:50 by yohya             #+#    #+#             */
/*   Updated: 2025/10/20 10:43:27 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

static void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char		*p;
	size_t				i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*temp;
	size_t	total;
	char	*empty;

	if (nmemb == 0 || size == 0)
	{
		empty = (char *)malloc(1);
		if (!empty)
			return (NULL);
		empty[0] = '\0';
		return (empty);
	}
	if (size > SIZE_MAX / nmemb)
		return (NULL);
	total = nmemb * size;
	temp = (char *)malloc(sizeof(char ) * total);
	if (!temp)
		return (NULL);
	ft_memset(temp, 0, total);
	return (temp);
}

// int	main(void)
// {
// 	size_t	nmemb = 5;
// 	size_t	size = 0;
// 	char	*arr;
// 	arr = ft_calloc(nmemb, size);
// 	if (!arr)
// 		return (0);
// 	for (size_t i = 0; i <= nmemb * size; i++)
// 		printf("%d", arr[i]);
// 	free(arr);
// 	return (0);
// }
