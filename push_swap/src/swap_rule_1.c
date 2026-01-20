/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rule_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:04:53 by yohya             #+#    #+#             */
/*   Updated: 2026/01/18 20:06:47 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp_value;
	int	temp_index;

	if (!a || a->size < 2)
		return ;
	temp_value = a->top->value;
	temp_index = a->top->index;
	a->top->value = a->top->next->value;
	a->top->index = a->top->next->index;
	a->top->next->value = temp_value;
	a->top->next->index = temp_index;
	write(1, "sa\n", 3);
}

void	rra(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	a->top = a->top->prev;
	write(1, "rra\n", 4);
}
