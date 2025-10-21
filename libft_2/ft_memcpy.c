/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:15:13 by yohya             #+#    #+#             */
/*   Updated: 2025/10/18 15:54:32 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char	*d_cpy;
	char	*s_cpy;
	size_t	j;

	d_cpy = (char *)dest;
	s_cpy = (char *)src;
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
// 	char src[5] = "aabb";
// 	char  dest[5] = "hgos";

// 	ft_memcpy(dest, src, sizeof(src));
// 	printf("%s\n", dest);

// 	char src1[5] = "aabb";
// 	char  dest1[5] = "hgos";

// 	ft_memcpy(dest1, src1, sizeof(src));
// 	printf("%s", dest1);
// 	return (0);
// }
