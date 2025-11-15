/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:23:25 by yohya             #+#    #+#             */
/*   Updated: 2025/11/15 12:23:45 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	feed_stash(int fd, char **stash, char *buf)
{
	ssize_t	n;

	n = 1;
	while (n > 0 && find_nl(*stash) == -1)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
			return (free(*stash), *stash = NULL, -1);
		if (n > 0)
		{
			buf[n] = '\0';
			*stash = gnl_strjoin_free(*stash, buf, n);
			if (!*stash)
				return (-1);
		}
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*buf;
	char			*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (free(stash), stash = NULL, NULL);
	if (feed_stash(fd, &stash, buf) < 0)
		return (free(buf), stash = NULL, NULL);
	free(buf);
	if (!stash || *stash == '\0')
		return (free(stash), stash = NULL, NULL);
	ret = extraction_stash(stash);
	if (!ret)
		return (free(stash), stash = NULL, NULL);
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

// int main(void)
// {
//     int fd = open("multiple_nl.txt", O_RDONLY);
//     char *line;
//     int i = 1;

//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("[%d] \"%s\"\n", i++, line);
//         free(line);
//     }
//     printf("EOF: get_next_line returned NULL\n");

//     // ここでもう一回呼んでみる
//     line = get_next_line(fd);
//     printf("After EOF, second call: %p\n", (void *)line);
//     if (line)
//         free(line);
// }
