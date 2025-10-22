/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:27:20 by yohya             #+#    #+#             */
/*   Updated: 2025/10/18 13:32:10 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

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

// int	main(void)
// {
// 	char	test[] = "hhhgjjjjka";
// 	char	*p;

// 	p = ft_strchr(test, '\0');
// 	if (p != NULL)
// 		printf("%s\n", p);
// 	else
// 		printf("not found\n");

// 	char	test1[] = "hhhgjjjjka";
// 	char	*p1;

// 	p1 = strchr(test1, '\0');
// 	if (p1 != NULL)
// 		printf("%s\n", p1);
// 	else
// 		printf("not found\n");

// 	return (0);
// }
