/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:04:53 by yohya             #+#    #+#             */
/*   Updated: 2025/12/22 17:32:13 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *s)
{
	s->top = NULL;
	s->size = 0;
}

t_node	*node_new(int value)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->value = value;
	n->index = 0;
	n->prev = n;
	n->next = n;
	return (n);
}

void	stack_push_bottom(t_stack *s, t_node *n)
{
	t_node	*top;
	t_node	*bottom;

	if (s->size == 0)
	{
		s->top = n;
		n->next = n;
		n->prev = n;
	}
	else
	{
		top = s->top;
		bottom = top->prev;
		n->next = top;
		n->prev = bottom;
		bottom->next = n;
		top->prev = n;
	}
	s->size++;
}

void	free_stack(t_stack *s)
{
	t_node	*cur;
	t_node	*next;
	int		i;
	int		n;

	if (!s || s->size == 0)
	{
		if (s)
			s->top = NULL;
		return ;

	}
	cur = s->top;
	n = s->size;
	i = 0;
	while (i < n)
	{
		next = cur->next;
		free(cur);
		cur = next;
		i++;
	}
	s->top = NULL;
	s->size = 0;
}