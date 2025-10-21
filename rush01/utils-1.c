/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:33:24 by rynitta           #+#    #+#             */
/*   Updated: 2025/09/14 14:33:26 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_atoi(char *str)
{
	long long int	ret;

	ret = 0;
	while ('0' <= *str && *str <= '9')
	{
		ret = ret * 10 + *str - '0';
		if (ret > INT_MAX)
			return (INT_MAX);
		++str;
	}
	return (ret);
}

int	is_numeric(char *str)
{
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (0);
		++str;
	}
	return (1);
}

int	ft_sqrt(int n)
{
	int	ret;

	if (n < 0)
		return (-1);
	else if (n == 0)
		return (0);
	ret = 1;
	while (ret < n / ret)
		++ret;
	if (ret * ret == n)
		return (ret);
	else
		return (-1);
}

void	ft_swap(int	*a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_reverse(int *array, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = array[i];
		array[i] = array[size - i - 1];
		array[size - i - 1] = tmp;
		++i;
	}
}
