/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:04:53 by yohya             #+#    #+#             */
/*   Updated: 2025/12/11 18:55:27 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *s, const char *name)
{
	t_node	*cur;
	int		i;

	printf("stack:%s\n", name);
	// if (s->size == 0 || s->top == NULL)
	// {
	// 	printf("(empty)\n");
	// 	return ;
	// }
	cur = s->top;
	i = 0;
	while (i < s->size)
	{
		printf("%d index=%d\n", cur->value, cur->index);
		cur = cur->next;
		i++;
	}
}
