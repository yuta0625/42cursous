/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:54:27 by yohya             #+#    #+#             */
/*   Updated: 2025/10/24 18:55:12 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	uc;

	uc = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == uc)
			return (str);
		str++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	unsigned char s[] = "ga";
// 	char *p1;
// 	char *p2;
// 	p1 = memchr(s, 'a', sizeof(s));
// 	printf("%s\n", p1);
// 	p2 = ft_memchr(s, 'a', sizeof(s));
// 	printf("%s\n", p2);
// }
