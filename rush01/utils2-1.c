/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:33:07 by rynitta           #+#    #+#             */
/*   Updated: 2025/09/14 14:33:09 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#define FAIL -1
#define SUCCESS 0

int	print_error(void)
{
	write(1, "Error\n", 6);
	return (-1);
}

void	print_map(int map[][9], int len_line)
{
	int		x;
	int		y;
	char	buf[9 * 2 + 1];

	y = 0;
	while (y < len_line)
	{
		x = 0;
		while (x < len_line)
		{
			buf[2 * x] = '0' + map[y][x];
			buf[2 * x + 1] = ' ';
			++x;
		}
		buf[2 * x] = '\n';
		write(1, buf, len_line * 2 + 1);
		++y;
	}
}

int	count_arrays(char **array_str)
{
	int	ret;

	ret = 0;
	while (array_str[ret])
		++ret;
	return (ret);
}
