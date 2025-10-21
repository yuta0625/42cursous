/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:34:19 by yohya             #+#    #+#             */
/*   Updated: 2025/09/16 12:09:15 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_putchar(char *str)
{
	int	j;

	j = 0;
	while (str[j] != '\0')
	{
		write(1, &str[j], 1);
		j++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc > 1)
	{
		while (argv[i] != NULL)
		{
			i++;
		}
		i = i - 1;
		while (i >= 1)
		{
			ft_putchar(argv[i]);
			write(1, "\n", 1);
			i--;
		}
	}
	return (0);
}
