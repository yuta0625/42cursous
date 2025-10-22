/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:04:30 by yohya             #+#    #+#             */
/*   Updated: 2025/10/22 12:09:48 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

static size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

// int	main(void)
// {
// 	int	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	char *c = "higejotajonaf hgiengaoij hgi7292";
// 	if (fd == -1)
// 		return (1);
// 	ft_putendl_fd(c, fd);
// 	close(fd);
// 	return (0);
// }
