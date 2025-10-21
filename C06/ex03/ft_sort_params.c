/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:08:53 by yohya             #+#    #+#             */
/*   Updated: 2025/09/16 17:01:19 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	j;

	j = 0;
	while (str[j] != '\0')
	{
		write(1, &str[j], 1);
		j++;
	}
}

void	ft_put_args(int argc, char **argv)
{
	int	n;

	n = 1;
	while (n < argc)
	{
		ft_putstr(argv[n]);
		ft_putstr("\n");
		n++;
	}
}

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_strcmp(char *a, char *b)
{
	int	k;

	k = 0;
	while (a[k] != '\0' && b[k] != '\0')
	{
		if (a[k] != b[k])
		{
			return (a[k] - b[k]);
		}
		k++;
	}
	return (a[k] - b[k]);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc > 1)
	{
		i = 1;
		while (i < argc - 1)
		{
			j = 1;
			while (j < argc - i)
			{
				if (ft_strcmp(argv[j], argv[j + 1]) > 0)
					ft_swap(&argv[j], &argv[j + 1]);
				j++;
			}
			i++;
		}
		ft_put_args(argc, argv);
	}
	return (0);
}
