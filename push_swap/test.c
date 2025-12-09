/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:04:53 by yohya             #+#    #+#             */
/*   Updated: 2025/12/09 17:09:00 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *s, const char *name)
{
	t_node	*cur;
	int		i;

	printf("=== stack %s ===\n", name);
	printf("size = %d\n", s->size);
	if (s->size == 0 || s->top == NULL)
	{
		printf("(empty)\n");
		return ;
	}
	cur = s->top;
	i = 0;
	while (i < s->size)
	{
		printf("[%d] value=%d index=%d\n", i, cur->value, cur->index);
		cur = cur->next;
		i++;
	}
	printf("---- end ----\n");
}
