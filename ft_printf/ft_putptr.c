/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:33:34 by yohya             #+#    #+#             */
/*   Updated: 2025/10/29 16:26:46 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	putchar_hex(char c)
{
	return ((int)write(1, &c, 1));
}

static int	ft_hexadecimal(unsigned long long n)
{
	int				i;
	char			*hex;

	i = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		i += ft_hexadecimal(n / 16);
	i += putchar_hex(hex[n % 16]);
	return (i);
}

int	ft_putptr(void *ptr)
{
	int	count;

	count += write(1, "0x", 2);
	if (ptr == NULL)
		count += write(1, "0", 1);
	else
		count += ft_hexadecimal((unsigned long long)ptr);
	return (count);
}
