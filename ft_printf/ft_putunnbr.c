/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:34:35 by yohya             #+#    #+#             */
/*   Updated: 2025/10/30 17:00:10 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunnbr(unsigned int n)
{
	unsigned long	nb;
	int				count;

	nb = (unsigned long)n;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putunnbr(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}

// static void	ft_putchar_ret(int c)
// {
// 	write(1, &c, 1);
// }

// void	ft_putunnbr_ret(int c)
// {
// 	unsigned long	nb;

// 	nb = (unsigned long)c;
// 	if (nb < 0)
// 		ft_putchar_ret('-');
// 	if (nb >= 10)
// 		ft_putunnbr_ret(nb / 10);
// 	ft_putchar_ret(nb % 10 + '0');
// }
// #include <stdio.h>
// int main(void)
// {
// 	int n = 4353;
// 	ft_putunnbr_ret(n);
// }
