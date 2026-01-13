/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 18:50:39 by yohya             #+#    #+#             */
/*   Updated: 2025/10/26 12:11:53 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// int	main(void)
// {
// 	char str[] = "strlen";
// 	printf("%d\n", ft_strlen(str));
// 	char str1[] = "strlen";
// 	printf("%lu", strlen(str1));
// }
