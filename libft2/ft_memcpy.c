/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:15:13 by yohya             #+#    #+#             */
/*   Updated: 2025/10/26 12:02:14 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char	*d_cpy;
	unsigned char	*s_cpy;
	size_t			j;

	if (!dest && !src)
		return (NULL);
	d_cpy = (unsigned char *)dest;
	s_cpy = (unsigned char *)src;
	j = 0;
	while (len > 0)
	{
		d_cpy[j] = s_cpy[j];
		j++;
		len--;
	}
	return (dest);
}

// int	main(void)
// {
// 	unsigned char src[] = "aabd";
// 	unsigned char dest[] = "      ";

// 	ft_memcpy(dest, src, sizeof(src));
// 	printf("%s\n", dest);

// 	unsigned char src1[] = "aabd";
// 	unsigned char dest1[] = "      ";;

// 	memcpy(dest1, src1, sizeof(src));
// 	printf("%s", dest1);
// 	return (0);
// }
