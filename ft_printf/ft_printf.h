/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:57:18 by yohya             #+#    #+#             */
/*   Updated: 2025/10/30 18:46:20 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "src/libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putptr(void *ptr);
int	ft_putnbr(int n);
int	ft_putunnbr(unsigned int n);
int	ft_puthex_lowercase(unsigned int n);
int	ft_puthex_uppercase(unsigned int n);

#endif
