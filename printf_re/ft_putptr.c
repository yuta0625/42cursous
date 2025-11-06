/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:33:34 by yohya             #+#    #+#             */
/*   Updated: 2025/11/06 10:22:28 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexadecimal(unsigned long long n)
{
	int		i;
	char	*ntr;

	i = 0;
	ntr = ft_itoa_hex(n);
	i += ft_putstr(ntr);
	free(ntr);
	return (i);
}

int	ft_putptr(void *ptr)
{
	int	m;

	m = 0;
	if (!ptr)
		return ((int)write(1, "(nil)", 5));
	m += write(1, "0x", 2);
	if (m == -1)
		return (-1);
	m += ft_hexadecimal((unsigned long long)ptr);
	return (m);
}

// #include <stdio.h>
// int main(void)
// {
// 	void *ptr = "4395";
// 	ft_printf("%p\n", ptr);
// 	printf("%p", ptr);
// }
