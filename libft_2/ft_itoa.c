/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:36:22 by yohya             #+#    #+#             */
/*   Updated: 2025/10/21 16:54:02 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static	int	malloc_count(long nb)
{
	int	n;

	n = 1;
	while (nb >= 10)
	{
		nb = nb / 10;
		n++;
	}
	return (n);
}

static void	fill_digits(char *ret, long nb, int count, int sign)
{
	while (count > 0)
	{
		--count;
		ret[count + sign] = (nb % 10) + '0';
		nb = nb / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*ret;
	long	nb;
	int		count;
	int		sign;

	nb = (long)n;
	if (nb < 0)
	{
		sign = 1;
		nb = -nb;
	}
	else
		sign = 0;
	count = malloc_count(nb);
	ret = (char *)malloc(sizeof(char) * (count + sign + 1));
	if (!ret)
		return (NULL);
	ret[count + sign] = '\0';
	fill_digits(ret, nb, count, sign);
	if (sign == 1)
		ret[0] = '-';
	return (ret);
}

// int	main(void)
// {
// 	int n = -4215;
// 	char *temp = ft_itoa(n);
// 	printf("%s", temp);
// 	free(temp);
// }
