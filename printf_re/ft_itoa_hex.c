/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:36:22 by yohya             #+#    #+#             */
/*   Updated: 2025/11/04 20:39:11 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	malloc_count(unsigned long long nb)
{
	size_t	n;

	n = 1;
	while (nb >= 16)
	{
		nb = nb / 16;
		n++;
	}
	return (n);
}

static void	fill_digits(char *ret, unsigned long long nb, int count, int sign)
{
	char	*hex;

	hex = "0123456789abcdef";
	while (count > 0)
	{
		--count;
		ret[count + sign] = (hex[nb % 16]);
		nb = nb / 16;
	}
}

char	*ft_itoa_hex(unsigned long long nb)
{
	char	*ret;
	int		count;
	int		sign;

	if (nb < 0)
	{
		sign = 1;
		nb = -nb;
	}
	else
		sign = 0;
	count = malloc_count(nb);
	ret = (char *)malloc(sizeof(char) * (count + sign + 1));
	if (!ret)
		return (NULL);
	ret[count + sign] = '\0';
	fill_digits(ret, nb, count, sign);
	if (sign == 1)
		ret[0] = '-';
	return (ret);
}
