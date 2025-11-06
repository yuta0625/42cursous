/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:26:51 by yohya             #+#    #+#             */
/*   Updated: 2025/11/06 17:03:22 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_format(char spec, va_list ap)
{
	int	w;

	w = 0;
	if (spec == '\0')
		return (0);
	if (spec == 'c')
		w += ft_putchar(va_arg(ap, int));
	else if (spec == 's')
		w += ft_putstr(va_arg(ap, char *));
	else if (spec == 'p')
		w += ft_putptr(va_arg(ap, void *));
	else if (spec == 'd' || spec == 'i')
		w += ft_putnbr(va_arg(ap, int));
	else if (spec == 'u')
		w += ft_putunnbr(va_arg(ap, unsigned int));
	else if (spec == 'x')
		w += ft_puthex_lowercase(va_arg(ap, unsigned int));
	else if (spec == 'X')
		w += ft_puthex_uppercase(va_arg(ap, unsigned int));
	else if (spec == '%')
		w += ft_putchar('%');
	return (w);
}

static int	print_text(const char *fmt, int *n)
{
	int	wr;

	wr = (int)write(1, &fmt[*n], 1);
	if (wr == -1)
		return (-1);
	return (1);
}

static	int	print_conv(const char *fmt, int *n, va_list *ap)
{
	int	l;
	int	cm;

	cm = 0;
	if (!fmt[*n])
		return (-1);
	if (fmt[*n] == '%')
	{
		*n++;
		l = ft_handle_format(fmt[*n], ap);
		if (l < 0)
			return (-1);
		cm += l;
	}
	return (cm);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;
	int		wc;

	i = 0;
	count = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			wc = print_conv(format, &i, &ap);
		else
			wc = print_text(format, &i);
		if (wc == -1)
			return (var_end(ap), -1);
		count += wc;
	}
	va_end(ap);
	return (count);
}

// #include <stdio.h>
// #include <limits.h>
// int main(void)
// {
// 	char c = 'q';
// 	char *str = "hello";
// 	void *ptr = "7398492";
// 	int n = 010;
// 	int j = INT_MAX;
// 	unsigned int ux = 64778;
// 	unsigned int xx = 4682;
// 	int	result = ft_printf("aafgaoi");
// 	int result1 = printf("aafgaoi");
// 	ft_printf("この文字は: %c\n" ,c);
// 	printf("この文字は: %c\n" ,c);
// 	ft_printf("この文字列は: %s\n",str);
// 	printf("この文字列は: %s\n",str);
// 	ft_printf("この16進数変換の値は: %p\n", ptr);
// 	printf("この16進数変換の値は: %p\n", ptr);
// 	ft_printf("この10進数の値は: %i %i\n", n, j);
// 	printf("この10進数の値は: %i %i\n", n, j);
// 	ft_printf("この数値の10進数の値は: %u\n", ux);
// 	printf("この数値の10進数の値は: %u\n", ux);
// 	ft_printf("この数値の16進数のlowercase値は: %x\n", xx);
// 	printf("この数値の16進数のlowercase値は: %x\n", xx);
// 	ft_printf("この数値の16進数のupeercase値は:: %X\n", xx);
// 	printf("この数値の16進数のupeercase値は:: %X\n", xx);
// 	ft_printf("この地域の今年の収穫量は前年の50%%である\n");
// 	printf("この地域の今年の収穫量は前年の50%%である\n");
// 	ft_printf("%d\n", result1);
// 	ft_printf("%d\n", result);
// 	printf("%d\n", result1);
// 	printf("%d", result);
// }
