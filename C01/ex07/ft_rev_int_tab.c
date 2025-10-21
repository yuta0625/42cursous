/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:26:05 by yohya             #+#    #+#             */
/*   Updated: 2025/09/08 09:45:11 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	j = size -1;
	while (i < size / 2)
	{
		ret = tab[i];
		tab[i] = tab[j];
		tab[j] = ret;
		i ++;
		j --;
	}
}

// int	main(void)
// {
// 	int	size = 6;
// 	int	tab[] = {11, 12, 13, 14, 15, 67};
// 	ft_rev_int_tab(tab, size);
// 	for (int i = 0; i < 6; i++)
// 		printf("%d ", tab[i]);
// 	printf("\n");
// }
