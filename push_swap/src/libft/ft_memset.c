/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:46:21 by yohya             #+#    #+#             */
/*   Updated: 2025/10/26 12:02:18 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char		*p;
	unsigned char		d;
	size_t				i;

	p = (unsigned char *)s;
	d = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		p[i] = d;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	unsigned char	buf[0];

// 	ft_memset(buf, 'A', sizeof(buf));
// 	printf("%s\n", buf);
// 	memset(buf, 'B', sizeof(buf));
// 	printf("%s", buf);
// }
