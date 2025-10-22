/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:47:01 by yohya             #+#    #+#             */
/*   Updated: 2025/10/19 15:02:37 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (!((unsigned char)s1[i] == (unsigned char)s2[i]))
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char s1[] = "agif";
// 	char s2[] = "agig";
// 	unsigned int n = 4;
// 	printf("%d\n", ft_strncmp(s1, s2, n));
// 	printf("%d", strncmp(s1, s2, n));
// }
