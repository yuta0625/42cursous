/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:26:51 by yohya             #+#    #+#             */
/*   Updated: 2025/10/29 17:59:49 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_handle_format(char spec, va_list ap)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (spec == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (spec == 'p')
		count += ft_putptr(va_arg(ap, void *));
	else if (spec == 'd' || spec == 'i')
		count += ft_putnbr(va_arg(ap, int));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_handle_format(format[i], ap);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

#include <stdio.h>
#include <limits.h>
int main(void)
{
	char c = 'q';
	char *str = "hello";
	void *ptr = "7398492";
	double n = 3.14;
	ft_printf("この文字は: %c\n" ,c);
	ft_printf("この文字列は: %s\n",str);
	ft_printf("この16進数変換の値は: %p\n", ptr);
	ft_printf("この10進数の値は: %i\n", n);
	printf("%i\n", n);
}
