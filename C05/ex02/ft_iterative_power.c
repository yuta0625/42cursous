/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:43:18 by yohya             #+#    #+#             */
/*   Updated: 2025/09/15 18:57:12 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	i = 1;
	if (power < 0)
	{
		return (0);
	}
	if (nb == 0 || power == 0)
	{
		return (1);
	}
	result = nb;
	while (i < power)
	{
		nb = nb * result;
		i++;
	}
	return (nb);
}

// int main(void)
// {
// 	int nb = 3;
// 	int power = 0;
// 	printf("%d", ft_iterative_power(nb, power));
// }
