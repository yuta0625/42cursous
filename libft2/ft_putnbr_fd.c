/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:15:08 by yohya             #+#    #+#             */
/*   Updated: 2025/10/22 12:36:36 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	int		sign;

	nb = (long)n;
	sign = 0;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_fd('-', fd);
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10 + '0'), fd);
}

// int	main(void)
// {
// 	int	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	int	n = -3539589;
// 	ft_putnbr_fd(n, fd);
// 	close(fd);
// 	return (0);
// }
