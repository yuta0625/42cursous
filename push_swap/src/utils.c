/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:04:53 by yohya             #+#    #+#             */
/*   Updated: 2026/01/13 15:42:56 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static void	free_split(char **sp)
{
	int	i;

	if (!sp)
		return ;
	i = 0;
	while (sp[i])
	{
		free(sp[i]);
		i++;
	}
	free(sp);
}

static void	cleanup_and_error(t_stack *a, char **sp)
{
	free_split(sp);
	free_stack(a);
	error_and_exit();
}

static int	push_tokens(t_stack *a, char **sp)
{
	int	j;

	j = 0;
	while (sp[j])
	{
		if (!add_token_to_stack(a, sp[j]))
			return (0);
		j++;
	}
	return (1);
}

void	fill_stack_from_args(int argc, char **argv, t_stack *a)
{
	int		i;
	char	**sp;

	stack_init(a);
	i = 1;
	while (i < argc)
	{
		sp = ft_split(argv[i], ' ');
		if (!sp || !push_tokens(a, sp))
			cleanup_and_error(a, sp);
		free_split(sp);
		i++;
	}
	if (a ->size == 0)
		cleanup_and_error(a, NULL);
}
