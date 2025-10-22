/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:46:21 by yohya             #+#    #+#             */
/*   Updated: 2025/10/22 12:45:45 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char		*p;
	size_t		i;

	p = (char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	char	buf[6];

// 	memset(buf, 'A', sizeof(buf));
// 	printf("%s\n", buf);
// 	ft_memset(buf, 'B', sizeof(buf));
// 	printf("%s", buf);
// }
