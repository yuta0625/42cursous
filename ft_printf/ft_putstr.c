/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:44:52 by yohya             #+#    #+#             */
/*   Updated: 2025/10/31 12:49:33 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return ((int)write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		count++;
	}
	return (count);
}
