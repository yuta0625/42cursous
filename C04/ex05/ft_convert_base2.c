/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:37:43 by wnakahar          #+#    #+#             */
/*   Updated: 2025/09/25 17:20:28 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str);
int	ft_atoi_base(char *str, char *base);

void	ft_putchar(char a)
{
	write(1, &a, 1);
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
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			base_len;
	long int	n;

	n = nbr;
	if (base_check(base))
	{
		base_len = ft_strlen(base);
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n < base_len)
		{
			ft_putchar(base[n % base_len]);
			return ;
		}
		if (n >= base_len)
		{
			ft_putnbr_base(n / base_len, base);
			ft_putchar(base[n % base_len]);
		}
		return ;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	i;

	(void)base_to;
	i = ft_atoi_base(nbr, base_from);
	printf("%d", i);
	return (0);
}

int main(void)
{
	char	*nbr = "101101";
	char	*base_from = "01";
	char	*base_to = "0123456789";
	ft_convert_base(nbr, base_from, base_to);
}
