/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:20:35 by yohya             #+#    #+#             */
/*   Updated: 2025/10/18 11:43:57 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stddef.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	char	*p;
	size_t	i;

	p = (char *)s;
	i = 0;
	while (i < n)
		p[i++] = '\0';
}

// int main(void)
// {
// 	char	buf[] = "hello";
// 	ft_bzero(buf+2, 2);
// 	printf("%s", buf);
// }
