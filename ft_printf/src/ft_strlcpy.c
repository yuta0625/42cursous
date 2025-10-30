/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:20:50 by yohya             #+#    #+#             */
/*   Updated: 2025/10/26 12:03:44 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	if (size == 0)
		return (i);
	while (j < size -1 && src[j])
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (i);
}

// int	main(void)
// {
// 	char src[] = " ";
// 	char dest[] = "agk";
// 	size_t size = 1;

// 	printf("%ld\n", ft_strlcpy(dest, src, size));
// 	printf("%ld", strlcpy(dest, src, size));
// }
