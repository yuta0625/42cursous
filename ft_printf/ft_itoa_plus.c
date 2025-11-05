/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:36:22 by yohya             #+#    #+#             */
/*   Updated: 2025/11/04 20:46:15 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	malloc_count(unsigned long nb)
{
	size_t	n;

	n = 1;
	while (nb >= 10)
	{
		nb = nb / 10;
		n++;
	}
	return (n);
}

static void	fill_digits(char *ret, unsigned long nb, int count, int sign)
{
	while (count > 0)
	{
		--count;
		ret[count + sign] = (nb % 10) + '0';
		nb = nb / 10;
	}
}

char	*ft_itoa_plus(unsigned int n)
{
	char			*ret;
	unsigned long	nb;
	int				count;
	int				sign;

	nb = (unsigned long)n;
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
