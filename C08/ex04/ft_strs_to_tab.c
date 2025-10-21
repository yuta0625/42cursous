/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:32:50 by yohya             #+#    #+#             */
/*   Updated: 2025/09/23 21:06:33 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	while (str[i])
		i++;
	dest = (char *)malloc(sizeof(char) *(i + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (j < i)
	{
		dest[j] = str[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*ret;

	ret = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		ret[i].size = ft_strlen(av[i]);
		ret[i].str = av[i];
		ret[i].copy = ft_strdup(av[i]);
		if (!ret[i].copy)
		{
			while (i > 0)
				free(ret[--i].copy);
			free(ret);
			return (NULL);
		}
		i++;
	}
	ret[i].str = 0;
	return (ret);
}

// int	main(void)
// {
// 	char	*av[] = {"hello", "world", "42", "tokyo"};
// 	int		ac = 4;
// 	t_stock_str	*temp = ft_strs_to_tab(ac, av);
// 	int j = 0;
// 	while (j < ac)
// 	{
// 		printf("%d\n", temp[j].size);
// 		printf("%s\n", temp[j].str);
// 		printf("%s\n", temp[j].copy);
// 		j++;
// 	}
// }
