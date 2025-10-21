/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:14:20 by yohya             #+#    #+#             */
/*   Updated: 2025/09/07 09:18:03 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

/*
int	main(void)
{
	int	a;
	int	b;

	a = 2;
	b = 1;
	printf("%d\n", a);
	printf("%d\n", b);
	ft_swap(&a, &b);
	printf("%d\n", a);
	printf("%d\n", b);
}
*/
