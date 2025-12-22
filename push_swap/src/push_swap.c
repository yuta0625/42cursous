/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:04:53 by yohya             #+#    #+#             */
/*   Updated: 2025/12/22 17:00:17 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc <= 1)
		return (0);
	fill_stack_from_args(argc, argv, &a);
	stack_init(&b);
	if (is_sorted(&a))
		return (0);
	assign_index_by_sort(&a);
	if (a.size == 2)
		sa(&a);
	else if (a.size == 3)
		sort_three(&a);
	else if (a.size <= 5)
		sort_four_five(&a, &b);
	else
		radix_sort(&a, &b);
	return (0);
}
