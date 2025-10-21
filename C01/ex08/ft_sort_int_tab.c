/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:37:13 by yohya             #+#    #+#             */
/*   Updated: 2025/09/07 09:41:05 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j ++;
		}
		i ++;
	}
}

/*
int	main(void)
{
	int	size = 6;
	int	tab[6] =  {12, 34, 56, 45, 21};
	ft_sort_int_tab(tab,size);
	for (int i = 0; i < 6; i++)
		printf("%d ", tab[i]);
	printf("\n");
}
*/
