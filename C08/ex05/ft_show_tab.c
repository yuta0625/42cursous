/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:31:54 by yohya             #+#    #+#             */
/*   Updated: 2025/09/23 21:10:07 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

// struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i++], 1);
	}
}

void	ft_putnbr(int size)
{
	if (size == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (size < 0)
	{
		ft_putchar('-');
		size = -size;
	}
	if (size >= 10)
	{
		ft_putnbr(size / 10);
	}
	ft_putchar(size % 10 + '0');
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}

// int	main(void)
// {
// 	char	*word[] = {"hello", "world", "tokyo"};
// 	int		ac = 3;
// 	t_stock_str *temp = ft_strs_to_tab(ac, word);
// 	ft_show_tab(temp);
// }
