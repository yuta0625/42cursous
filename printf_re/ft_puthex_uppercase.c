/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:00:16 by yohya             #+#    #+#             */
/*   Updated: 2025/11/04 20:23:26 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_hexadecimal_uppercase(unsigned int n)
{
	int		i;
	char	*let;

	i = 0;
	let = ft_itoa_hex_toupper(n);
	i += ft_putstr(let);
	free(let);
	return (i);
}

int	ft_puthex_uppercase(unsigned int n)
{
	int	q;

	q = 0;
	if (n == 0)
	{
		q += ft_putchar('0');
		return (q);
	}
	q += ft_hexadecimal_uppercase(n);
	return (q);
}
