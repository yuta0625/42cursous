/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:33:28 by yohya             #+#    #+#             */
/*   Updated: 2025/09/07 09:21:22 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	ultimate;
	int	swap;

	ultimate = *a / *b;
	swap = *a % *b;
	*a = ultimate;
	*b = swap;
}

/*
int	main(void)
{
	int	a;
	int	b;

	a = 7;
	b = 3;
	printf("%d\n", a);
	printf("%d\n", b);
	ft_ultimate_div_mod(&a, &b);
	printf("%d\n", a);
	printf("%d\n", b);
}
*/
