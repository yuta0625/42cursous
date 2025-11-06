/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:24:02 by yohya             #+#    #+#             */
/*   Updated: 2025/11/04 19:58:39 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexadecimal_lowercase(unsigned int n)
{
	int		i;
	char	*let;

	i = 0;
	let = ft_itoa_hex(n);
	i += ft_putstr(let);
	free(let);
	return (i);
}

int	ft_puthex_lowercase(unsigned int n)
{
	int	p;

	p = 0;
	if (n == 0)
	{
		p += ft_putchar('0');
		return (p);
	}
	p += ft_hexadecimal_lowercase(n);
	return (p);
}
