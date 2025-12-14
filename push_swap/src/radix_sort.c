/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:04:53 by yohya             #+#    #+#             */
/*   Updated: 2025/12/14 18:06:43 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//基数ソート
void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	max_index;
	int	bit;
	int	i;
	int	n;

	max_index = a->size -1;
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	bit = 0;
	while (bit++ < max_bits)
	{
		n = a->size;
		i = 0;
		while (i++ < n)
		{
			if (((a->top->index >> bit) & 1) == 0)
				pb(a, b);
			else
				ra(a);
		}
		while (b->size > 0)
			pa(a, b);
	}
}
