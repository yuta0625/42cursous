/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 21:37:55 by yohya             #+#    #+#             */
/*   Updated: 2025/09/13 22:10:17 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
	{
		return (0);
	}
	if (nb == 0 || power == 0)
	{
		return (1);
	}
	return (nb * ft_recursive_power(nb, power - 1));
}

// int main(void)
// {
// 	int nb = 3;
// 	int power = 5;
// 	printf("%d", ft_recursive_power(nb, power));
// }
