/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:10:03 by yohya             #+#    #+#             */
/*   Updated: 2025/09/15 18:54:22 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (2);
	while (i < nb)
	{
		if (nb % i == 0)
		{
			i = 2;
			nb++;
		}
		i++;
	}
	return (nb);
}

// int	main(void)
// {
// 	int nb = 78;
// 	printf("%d",ft_find_next_prime(nb));
// }
