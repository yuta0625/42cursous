/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:27:20 by yohya             #+#    #+#             */
/*   Updated: 2025/10/24 18:33:51 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;

	chr = (char)c;
	while (*s)
	{
		if (*s == chr)
			return ((char *)s);
		s++;
	}
	if (chr == '\0')
		return ((char *)s);
	return (NULL);
}

// #include <string.h>
// int	main(void)
// {
// 	char	test[] = "hhhgjjjjka";
// 	char	*p;

// 	p = ft_strchr(test, 'g');
// 	if (p != NULL)
// 		printf("%s\n", p);
// 	else
// 		printf("not found\n");

// 	char	test1[] = "hhhgjjjjka";
// 	char	*p1;

// 	p1 = strchr(test1, 'g');
// 	if (p1 != NULL)
// 		printf("%s\n", p1);
// 	else
// 		printf("not found\n");

// 	return (0);
// }
