/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:03:33 by yohya             #+#    #+#             */
/*   Updated: 2025/09/10 14:35:56 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (!(s1[i] == s2[i]))
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

// int	main(void)
// {
// 	char s1[] = "abfdw";
// 	char s2[] = "abfde";
// 	printf("%d\n", ft_strcmp(s1,s2));
// 	printf("%d", ft_strcmp(s1, s2));
// }
