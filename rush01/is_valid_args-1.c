/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:12:25 by rynitta           #+#    #+#             */
/*   Updated: 2025/09/14 14:12:29 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int	is_numeric(char *str);
int	ft_atoi(char *str);
int	ft_sqrt(int n);

static bool	_is_valid_argc(int argc)
{
	int	len_line;

	len_line = argc / 4;
	if (argc % 4 != 0 || len_line < 1 || len_line > 9)
		return (false);
	return (true);
}

static bool	__is_only_numeric_argv(char **argv)
{
	while (*argv)
	{
		if (!is_numeric(*argv))
			return (false);
		++argv;
	}
	return (true);
}

static bool	__is_valid_argv_range(int argc, char **argv)
{
	int	tmp;

	while (*argv)
	{
		tmp = ft_atoi(*argv);
		if (tmp < 1 || tmp > argc / 4)
			return (false);
		++argv;
	}
	return (true);
}

static bool	_is_valid_argv(int argc, char **argv)
{
	if (!__is_only_numeric_argv(argv))
		return (false);
	if (!__is_valid_argv_range(argc, argv))
		return (false);
	return (true);
}

int	is_valid_args(int argc, char **argv)
{
	if (!_is_valid_argc(argc))
		return (false);
	if (!_is_valid_argv(argc, argv))
		return (false);
	return (true);
}
