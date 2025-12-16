/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:04:53 by yohya             #+#    #+#             */
/*   Updated: 2025/12/16 10:03:00 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc <= 1)
		return ;
	fill_stack_from_args(argc, argv, &a);
	stack_init(&b);
	assign_index_by_sort(&a);
	radix_sort(&a, &b);
}

// #include <stdio.h>
// void	print_stack(t_stack *s, const char *name)
// {
// 	t_node	*cur;
// 	int		i;

// 	printf("stack:%s\n", name);
// 	cur = s->top;
// 	i = 0;
// 	while (i < s->size)
// 	{
// 		printf("%d index=%d\n", cur->value, cur->index);
// 		cur = cur->next;
// 		i++;
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	push_swap(argc, argv);
// 	return (0);
// }
