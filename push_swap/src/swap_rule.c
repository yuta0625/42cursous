/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:04:53 by yohya             #+#    #+#             */
/*   Updated: 2026/01/18 20:07:01 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*pop_top(t_stack *s)
{
	t_node	*n;

	if (!s || s->size == 0)
		return (NULL);
	n = s->top;
	if (s->size == 1)
		s->top = NULL;
	else
	{
		n->prev->next = n->next;
		n->next->prev = n->prev;
		s->top = n->next;
	}
	n->next = n;
	n->prev = n;
	s->size--;
	return (n);
}

static void	push_top(t_stack *s, t_node *n)
{
	t_node	*top;
	t_node	*bottom;

	if (!s || !n)
		return ;
	if (s->size == 0)
		s->top = n;
	else
	{
		top = s->top;
		bottom = top->prev;
		n->next = top;
		n->prev = bottom;
		bottom->next = n;
		top->prev = n;
		s->top = n;
	}
	s->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*n;

	n = pop_top(b);
	if (!n)
		return ;
	push_top(a, n);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*n;

	n = pop_top(a);
	if (!n)
		return ;
	push_top(b, n);
	write(1, "pb\n", 3);
}

void	ra(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	a->top = a->top->next;
	write(1, "ra\n", 3);
}
