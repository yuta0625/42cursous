/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:15:04 by yohya             #+#    #+#             */
/*   Updated: 2025/09/25 14:48:39 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	*ft_range(int min, int max)
{
	int	*ret;
	int	i;
	int	j;

	ret = (int *)malloc(sizeof(int) *((max - min)));
	if (!ret)
		return (NULL);
	if (min >= max || min == max)
		return (NULL);
	i = min;
	j = 0;
	while (i < max)
	{
		ret[j] = i;
		i++;
		j++;
	}
	return (ret);
}

int main(void)
{
	int	min = -10000;
	int max = 467;
	int *result = ft_range(min,max);
	for(int i = 0; i < max - min; i++)
		printf("%d ", result[i]);
	return (0);
}
