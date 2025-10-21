/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:49:33 by yohya             #+#    #+#             */
/*   Updated: 2025/10/19 14:57:57 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d_cpy;
	char	*s_cpy;

	d_cpy = (char *)dest;
	s_cpy = (char *)src;
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
// 	char	src[] = "apple";
// 	ft_memmove(src+1, src, sizeof(src));
// 	printf("%s", src);
// }
