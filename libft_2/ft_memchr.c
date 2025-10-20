/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:54:27 by yohya             #+#    #+#             */
/*   Updated: 2025/10/18 16:40:53 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	c &= 255;
	if (str == NULL)
		return (NULL);
	while (n--)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	unsigned char s[] = "ag5hai";
// 	char *p1;
// 	char *p2;
// 	p1 = memchr(s, '5', sizeof(s));
// 	if (p1 != NULL)
// 		printf("%s\n", p1);
// 	else
// 		printf("not found\n");
// 	p2 = ft_memchr(s, '5', sizeof(s));
// 	if (p2 != NULL)
// 		printf("%s\n", p2);
// 	else
// 		printf("not found");
// }
