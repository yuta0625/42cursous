/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:18:42 by yohya             #+#    #+#             */
/*   Updated: 2025/09/22 19:20:05 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_word(int size, char **strs)
{
	int	j;
	int	str_count;

	j = 0;
	str_count = 0;
	while (j < size)
	{
		str_count += ft_strlen(strs[j]);
		j++;
	}
	return (str_count);
}

char	*ft_empty_str(void)
{
	char	*empty;

	empty = (char *)malloc(1);
	if (empty)
		empty[0] = '\0';
	return (empty);
}

int	copy_ret(char *dest, char **strs, int size, char *sep)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			dest[k++] = strs[i][j++];
		if (i < size - 1)
		{
			j = 0;
			while (sep[j])
				dest[k++] = sep[j++];
		}
		i++;
	}
	dest[k] = '\0';
	return (k);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_len;
	char	*ret;

	if (size <= 0)
		return (ft_empty_str());
	total_len = count_word(size, strs) + ((size - 1) * ft_strlen(sep));
	ret = (char *)malloc(sizeof(char) *(total_len + 1));
	if (!ret)
		return (0);
	copy_ret(ret, strs, size, sep);
	return (ret);
}

// int main(void)
// {
//     char *strs[] = {"hello", "world"};
//     int size = 2;
//     char *sep = ",";
//     char *temp = ft_strjoin(size, strs, sep);
//     printf("%s", temp);
//     free(temp);
//     return 0;
// }
