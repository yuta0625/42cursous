/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:00:16 by yohya             #+#    #+#             */
/*   Updated: 2025/10/30 16:59:32 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexadecimal(unsigned long n)
{
	int				i;
	char			*hex;

	i = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		i += ft_hexadecimal(n / 16);
	i += ft_putchar(ft_toupper(hex[n % 16]));
	return (i);
}

int	ft_puthex_uppercase(unsigned int n)
{
	unsigned long	nb;
	int				count;

	nb = (unsigned long)n;
	count = 0;
	count += ft_hexadecimal(nb);
	return (count);
}
