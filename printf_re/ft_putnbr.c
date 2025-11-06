/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:40:34 by yohya             #+#    #+#             */
/*   Updated: 2025/11/06 10:23:30 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_putnbr(int n)
{
	long	nb;
	char	*str;
	int		ns;

	nb = (long)n;
	ns = 0;
	str = ft_itoa(nb);
	ns += ft_putstr(str);
	free(str);
	return (ns);
}
