/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:39:06 by yohya             #+#    #+#             */
/*   Updated: 2025/10/24 16:43:51 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int	main(void)
// {
// 	int	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd == -1)
// 		return (1);
// 	ft_putchar_fd('A', fd);
// 	close(fd);
// 	return (0);
// }
