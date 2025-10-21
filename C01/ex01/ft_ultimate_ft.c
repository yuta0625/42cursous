/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:06:55 by yohya             #+#    #+#             */
/*   Updated: 2025/09/07 09:17:04 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

void	ft_ultimate_1(int *******p7)
{
	int	********p8;
	int	*********nbr;

	p8 = &p7;
	nbr = &p8;
	ft_ultimate_ft(nbr);
}

void	ft_ultimate(int ***p3)
{
	int	****p4;
	int	*****p5;
	int	******p6;
	int	*******p7;

	p4 = &p3;
	p5 = &p4;
	p6 = &p5;
	p7 = &p6;
	ft_ultimate_1(p7);
}

/*
int	main(void)
{
	int	a;
	int	*p1;
	int	**p2;
	int	***p3;

	a = 1;
	p1 = &a;
	p2 = &p1;
	p3 = &p2;
	printf("%d\n", a);
	ft_ultimate(p3);
	printf("%d\n", a);
	return (0);
}
*/
