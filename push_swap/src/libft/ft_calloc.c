/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:12:50 by yohya             #+#    #+#             */
/*   Updated: 2025/10/27 18:32:39 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*temp;
	size_t			total;
	unsigned char	*empty;

	if (nmemb == 0 || size == 0)
	{
		empty = (unsigned char *)malloc(0);
		return (empty);
	}
	if (size > SIZE_MAX / nmemb)
		return (NULL);
	total = nmemb * size;
	temp = (unsigned char *)malloc(sizeof(unsigned char) * total);
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
