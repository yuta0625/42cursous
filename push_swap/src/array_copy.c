/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:04:53 by yohya             #+#    #+#             */
/*   Updated: 2025/12/13 19:22:20 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//配列のコピー
int	*stack_to_array(t_stack *a)
{
	int		*arr;
	t_node	*cur;
	int		i;

	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		error_and_exit();
	cur = a->top;
	i = 0;
	while (i < a->size)
	{
		arr[i] = cur->value;
		cur = cur->next;
		i++;
	}
	return (arr);
}


