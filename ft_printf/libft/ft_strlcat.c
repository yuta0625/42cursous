/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:38:59 by yohya             #+#    #+#             */
/*   Updated: 2025/10/26 12:03:39 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = 0;
	s_len = 0;
	while (dest[d_len] && d_len < size)
		d_len++;
	while (src[s_len])
		s_len++;
	if (d_len == size)
		return (size + s_len);
	i = 0;
	while (src[i] && (d_len + i + 1) < size)
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (d_len + s_len);
}

// int	main(void)
// {
// 	char src[] = "abcde21123123";
// 	char dest[] = "affa";
// 	size_t size = 1;

// 	printf("%zu\n", ft_strlcat(dest, src, size));
// 	printf("%zu", strlcat(dest, src, size));
// }
