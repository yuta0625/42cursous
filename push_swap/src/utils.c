/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:04:53 by yohya             #+#    #+#             */
/*   Updated: 2025/12/15 16:24:40 by yohya            ###   ########.fr       */
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

int	is_duplicate_in_stack(t_stack *a, int value)
{
	t_node	*cur;
	int		i;

	if (!a || a->size == 0)
		return (0);
	cur = a->top;
	i = 0;
	while (i < a->size)
	{
		if (cur->value == value)
			return (1);
		cur = cur->next;
		i++;
	}
	return (0);
}

static void	add_token_to_stack(t_stack *a, char *tok)
{
	int		value;
	t_node	*node;

	if (!is_valid_integer_string(tok))
		error_and_exit();
	if (!to_number_with_check(tok, &value))
		error_and_exit();
	if (is_duplicate_in_stack(a, value))
		error_and_exit();
	node = node_new(value);
	if (!node)
		error_and_exit();
	stack_push_bottom(a, node);
}

void	fill_stack_from_args(int argc, char **argv, t_stack *a)
{
	int		i;
	int		j;
	char	**sp;

	stack_init(a);
	i = 1;
	while (i < argc)
	{
		sp = ft_split(argv[i], ' ');
		if (!sp)
			error_and_exit();
		j = 0;
		while (sp[j])
		{
			add_token_to_stack(a, sp[j]);
			j++;
		}
		free_split(sp);
		i++;
	}
	if (a ->size == 0)
		error_and_exit();
}
