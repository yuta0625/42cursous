/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:13:34 by yohya             #+#    #+#             */
/*   Updated: 2025/09/25 16:15:09 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_valid_base(char *base)
{
	int	len;
	int	i;
	int	j;

	len = ft_strlen(base);
	if (len < 2)
		return (0);
	i = 0;
	while (i < len)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	n;
	int		b;

	n = (long)nbr;
	b = ft_strlen(base);
	if (!ft_valid_base(base))
		return ;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}

	if (n >= b)
		ft_putnbr_base((int)(n / b), base);
	ft_putchar(base[(n % b)]);
}

int	main(void)
{
	int nbr = 13;
	char *base = "0123456789";
	ft_putnbr_base(nbr, base);
}
