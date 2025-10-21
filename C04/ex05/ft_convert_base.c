/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:37:30 by wnakahar          #+#    #+#             */
/*   Updated: 2025/09/25 17:16:42 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char a);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		j = 0;
		while (base[j])
		{
			if (i != j && base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if ((base[i] >= 9 && base[i] <= 13) || (base[i] == ' '))
			return (0);
		i++;
	}
	return (1);
}

int	ft_checkindex(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	if (!base_check(base))
		return (0);
	i = 0;
	nb = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_checkindex(str[i], base) != -1)
	{
		nb *= ft_strlen(base);
		nb += ft_checkindex(str[i], base);
		i++;
	}
	return ((int)nb * sign);
}
