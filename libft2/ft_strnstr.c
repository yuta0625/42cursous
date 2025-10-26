/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:04:21 by yohya             #+#    #+#             */
/*   Updated: 2025/10/26 13:20:10 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	size_t	k;

	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	j = 0;
	while (j < len && big[j])
	{
		k = 0;
		if (big[j] == little[0])
		{
			while (j + k < len && little[k] && big[j + k] == little[k])
				k++;
			if (k == ft_strlen(little))
				return ((char *)(big + j));
		}
		j++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char *largestring = "Foo Bar Baz";
//     const char *smallstring = "Bar";
//     char       *ptr;

//     ptr = strnstr(largestring, smallstring, 8);
// 	if (ptr != NULL)
// 		printf("%s\n", ptr);
// 	else
// 		printf("not found\n");

// 	const char *largestring1 = "Foo Bar Baz";
//     const char *smallstring1 = "Bar";
//     char       *ptr1;

//     ptr1 = strnstr(largestring1, smallstring1, 8);
// 	if (ptr1 != NULL)
// 		printf("%s\n", ptr1);
// 	else
// 		printf("not found\n");

// }
