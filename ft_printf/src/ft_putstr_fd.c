/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:54:14 by yohya             #+#    #+#             */
/*   Updated: 2025/10/24 16:39:59 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

// int	main(void)
// {
// 	int	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	char *c = "higejotajonaf hgiengaoij hgi7292";
// 	if (fd == -1)
// 		return (1);
// 	ft_putstr_fd(c, fd);
// 	close(fd);
// 	return (0);
// }
