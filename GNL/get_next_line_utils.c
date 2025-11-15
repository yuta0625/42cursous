/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:09:44 by yohya             #+#    #+#             */
/*   Updated: 2025/11/07 11:32:29 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_nl(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	gnl_strchr(const char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*gnl_strjoin_free(char *old, const char *buf, ssize_t n)
{
	size_t	old_len;
	char	*new_str;
	size_t	i;
	size_t	j;

	old_len = 0;
	i = 0;
	j = 0;
	if (old)
		while (old[old_len])
			old_len++;
	new_str = (char *)malloc(sizeof(char) * (old_len + (size_t)n + 1));
	if (!new_str)
		return (free(old), NULL);
	while (i < old_len)
	{
		new_str[i] = old[i];
		i++;
	}
	while (j < (size_t)n)
		new_str[i++] = buf[j++];
	new_str[i] = '\0';
	free(old);
	return (new_str);
}

char	*extraction_stash(char *stash)
{
	size_t	i;
	char	*let;
	size_t	j;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (i == 0 || stash[0] == '\0')
		return (NULL);
	let = (char *)malloc(sizeof(char) * (i + 1));
	if (!let)
		return (NULL);
	j = 0;
	while (j < i)
	{
		let[j] = stash[j];
		j++;
	}
	let[j] = '\0';
	return (let);
}

char	*trim_stash(char *stash)
{
	int		nl;
	int		len;
	int		j;
	char	*rest;

	nl = find_nl(stash);
	if (nl == -1)
		return (free(stash), NULL);
	len = 0;
	while (stash[nl + len + 1])
		len++;
	if (len == 0)
		return (free(stash), NULL);
	rest = (char *)malloc(sizeof(char) * (len + 1));
	if (!rest)
		return (free(stash), NULL);
	j = 0;
	while (j < len)
	{
		rest[j] = stash[nl + j + 1];
		j++;
	}
	rest[j] = '\0';
	free(stash);
	return (rest);
}
