/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:49:33 by yohya             #+#    #+#             */
/*   Updated: 2025/10/29 15:25:21 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d_cpy;
	unsigned char	*s_cpy;

	if (!dest && !src)
		return (NULL);
	d_cpy = (unsigned char *)dest;
	s_cpy = (unsigned char *)src;
	if (dest <= src)
	{
		while (n--)
			*d_cpy++ = *s_cpy++;
	}
	else
	{
		d_cpy += n;
		s_cpy += n;
		while (n--)
			*--d_cpy = *--s_cpy;
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	unsigned char src[] = "apple";
// 	//unsigned char dest[] = " ";

// 	ft_memmove(src + 2, src, 2);
// 	printf("%s\n", src + 2);
// 	unsigned char src1[] = "apple";
// 	//unsigned char dest1[] = " ";
// 	memmove(src + 2, src1, 2);
// 	printf("%s", src + 2);
// }
