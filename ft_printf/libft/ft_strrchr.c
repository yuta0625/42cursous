/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:18:37 by yohya             #+#    #+#             */
/*   Updated: 2025/10/26 12:12:38 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	chr1;
	int		len;

	chr1 = (char)c;
	len = 0;
	while (s[len])
		len++;
	while (len >= 0)
	{
		if (s[len] == chr1)
			return ((char *)&s[len]);
		len--;
	}
	if (chr1 == '\0')
		return ((char *)&s[len]);
	return (NULL);
}

// int	main(void)
// {
// 	char	test[] = "hhhgjjjjka";
// 	char	*p;
// 	p = strrchr(test, 'j');
// 	if (p != NULL)
// 		printf("%s\n", p);
// 	else
// 		printf("not found\n");

// 	char	test1[] = "hhhgjjjjka";
// 	char	*p1;
// 	p1 = ft_strrchr(test1, 'j');
// 	if (p1 != NULL)
// 		printf("%s\n", p1);
// 	else
// 		printf("not found\n");
// }
