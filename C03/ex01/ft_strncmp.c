/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:47:01 by yohya             #+#    #+#             */
/*   Updated: 2025/09/10 14:38:25 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (!(s1[i] == s2[i]))
		{
			return (s1[i] - s2[i]);
		}
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
