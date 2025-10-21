/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:31:42 by yohya             #+#    #+#             */
/*   Updated: 2025/09/22 11:18:54 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	len;
	int	i;
	int	j;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	len = max - min;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (-1);
	i = min;
	j = 0;
	while (j < len)
	{
		arr[j] = i;
		j++;
		i++;
	}
	*range = arr;
	return (len);
}

// int main(void)
// {
// 	int min = 32;
// 	int max = 31;
// 	int *p;
// 	int n = ft_ultimate_range(&p, min, max);
// 	printf("%d\n", n);
// 	for(int i = 0;i < max - min;i++)
// 		printf("%d " , p[i]);
// }
