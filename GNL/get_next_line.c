/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:23:25 by yohya             #+#    #+#             */
/*   Updated: 2025/11/05 20:43:40 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*buf;
	ssize_t			n;
	char			*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	n = 1;
	while ((!gnl_strchr(stash)) && n > 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
			return (free(buf), NULL);
		buf[n] = '\0';
		if (n > 0)
			stash = gnl_strjoin_free(stash, buf, n);
		if (!stash)
			return (free(buf), NULL);
	}
	free(buf);
	if (!stash || *stash == '\0')
		return (free(stash), stash = NULL, NULL);
	ret = extraction_stash(stash);
	stash = trim_stash(stash);
	return (ret);
}

// int main(void)
// {
//     int fd = open("output.txt", O_RDONLY);
//     if (fd == -1)
//         return (1);
//     char *line;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
//     close(fd);
//     return (0);
// }
