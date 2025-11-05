/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:44:52 by yohya             #+#    #+#             */
/*   Updated: 2025/11/04 14:35:32 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	r;
	int	j;

	i = 0;
	r = 0;
	if (!str)
		return ((int)write(1, "(null)", 6));
	while (str[i])
	{
		j = write(1, &str[i], 1);
		if (j == -1)
			return (-1);
		else
			r += j;
		i++;
	}
	return (r);
}
