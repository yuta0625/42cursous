/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:20:50 by yohya             #+#    #+#             */
/*   Updated: 2025/09/11 18:31:33 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
	{
		len++;
		if (size > 0)
		{
			while (i < size -1 && src[i] != '\0')
			{
				dest[i] = src[i];
				i++;
			}
			dest[i] = '\0';
		}
	}
	return (len);
}

int	main(void)
{
	char src[] = "abcde21123123";
	char dest[7];
	unsigned int size = 3;

	printf("%d\n", ft_strlcpy(dest, src, size));
	// printf("%s", dest);
}
