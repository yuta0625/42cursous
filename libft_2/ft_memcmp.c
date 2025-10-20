/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:41:49 by yohya             #+#    #+#             */
/*   Updated: 2025/10/18 17:40:25 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stddef.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
		n--;
	}
	return (0);
}

// int	main(void)
// {
// 	char buf[] = "ABCD5EFGH";
// 	char buf2[] = "ABC123456";

// 	int i = memcmp(buf, buf2, 4);
// 	printf("%d\n", i);
// 	int j = ft_memcmp(buf, buf2, 4);
// 	printf("%d\n", j);
// 	return (0);
// }
