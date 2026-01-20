/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:04:53 by yohya             #+#    #+#             */
/*   Updated: 2026/01/18 19:32:47 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_index_pos(t_stack *a)
{
	t_node	*cur;
	int		min_index;
	int		i;
	int		target_pos;

	cur = a->top;
	min_index = a->size;
	target_pos = 0;
	i = 0;
	while (i < a->size)
	{
		if (cur->index < min_index)
		{
			min_index = cur->index;
			target_pos = i;
		}
		cur = cur->next;
		i++;
	}
	return (target_pos);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (a->size < 2)
		return ;
	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_four_five(t_stack *a, t_stack *b)
{
	int	min_pos;

	while (a->size > 3)
	{
		min_pos = get_min_index_pos(a);
		if (min_pos <= a->size / 2)
		{
			while (min_pos-- > 0)
				ra(a);
		}
		else
		{
			while (min_pos++ < a->size)
				rra(a);
		}
		pb(a, b);
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}
