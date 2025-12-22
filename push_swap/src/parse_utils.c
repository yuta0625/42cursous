/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:04:53 by yohya             #+#    #+#             */
/*   Updated: 2025/12/22 17:38:25 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_integer_string(char *s)
{
	int	i;

	if (!s || s[0] == '\0')
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (!ft_isdigit((unsigned char)s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	to_number_with_check(char *s, int *out)
{
	int			sign;
	long long	res;
	int			i;

	sign = 1;
	res = 0;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		res = res * 10 + (s[i] - '0');
		if (res * sign > INT_MAX || res * sign < INT_MIN)
			return (0);
		i++;
	}
	*out = (int)(sign * res);
	return (1);
}

int	is_sorted(t_stack *s)
{
	t_node	*cur;
	int		i;

	if (s->size < 2)
		return (1);
	cur = s->top;
	i = 0;
	while (i < s->size - 1)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
		i++;
	}
	return (1);
}
