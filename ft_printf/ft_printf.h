/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:57:18 by yohya             #+#    #+#             */
/*   Updated: 2025/11/04 20:49:07 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putptr(void *ptr);
int		ft_putnbr(int n);
int		ft_putunnbr(unsigned int n);
int		ft_puthex_lowercase(unsigned int n);
int		ft_puthex_uppercase(unsigned int n);
char	*ft_itoa_hex(unsigned long long nb);
char	*ft_itoa_hex_toupper(unsigned int n);
char	*ft_itoa_plus(unsigned int n);

#endif
