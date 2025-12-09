/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:04:53 by yohya             #+#    #+#             */
/*   Updated: 2025/12/09 17:35:53 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

int	to_number(char *str)
{
	long	sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!(*str >= '0' && *str <= '9'))
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (sign * result > INT_MAX || sign * result < INT_MIN)
			return (0);
		str++;
	}
	if (*str != '\0')
		return (0);
	return (result * sign);
}

void	error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	add_number_str_to_stack(t_stack *a, char *s)
{
	int		value;
	t_node	*node;

	if (*s == '\0')
		error_and_exit();
	value = to_number(s);
	node = node_new(value);
	if (!node)
		error_and_exit();
	stack_push_bottom(a, node);
}

void	fill_stack_from_args(int argc, char **argv, t_stack *a)
{
	int		i;
	int		j;
	char	**split;

	stack_init(a);
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			error_and_exit();
		j = 0;
		while (split[j])
		{
			add_number_str_to_stack(a, split[j]);
			j++;
		}
		i++;
	}
}

void	set_index(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	int		i;
	int		j;
	int		count;

	if (!stack || !stack->top || stack->size <= 0)
		return ;
	current = stack->top;
	i = 0;
	while (i < stack->size)
	{
		count = 0;
		compare = stack->top;
		j = 0;
		while (j < stack->size)
		{
			if (compare->value < current->value)
				count++;
			else if (compare != current && compare->value == current->value)
				error_and_exit();
			compare = compare->next;
			j++;
		}
		current->index = count;
		current = current->next;
		i++;
	}
}
