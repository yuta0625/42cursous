/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:49:33 by yohya             #+#    #+#             */
/*   Updated: 2025/10/26 12:03:07 by yohya            ###   ########.fr       */
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

// int	main(void)
// {
// 	unsigned char src[] = "apple";
// 	unsigned char dest[] = " ";

// 	ft_memmove(dest, src, sizeof(src));
// 	printf("%s", src);
// }
