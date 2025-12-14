/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:04:53 by yohya             #+#    #+#             */
/*   Updated: 2025/12/14 18:45:25 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//基数ソート

static int	get_max_bits(int n)
{
	int	bits;

	bits = 0;
	while ((n >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	bit;
	int	i;
	int	n;

	if (!a || a->size < 2)
		return ;
	max_bits = get_max_bits(a->size -1);
	bit = 0;
	while (bit < max_bits)
	{
		n = a->size;
		i = 0;
		while (i < n)
		{
			if (((a->top->index >> bit) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			i++;
		}
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
}
