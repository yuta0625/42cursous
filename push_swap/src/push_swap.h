/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:04:53 by yohya             #+#    #+#             */
/*   Updated: 2026/01/18 20:05:15 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

void	stack_init(t_stack *s);
t_node	*node_new(int value);
void	stack_push_bottom(t_stack *s, t_node *n);
void	free_stack(t_stack *s);
void	fill_stack_from_args(int argc, char **argv, t_stack *a);
int		add_token_to_stack(t_stack *a, char *tok);
void	error_and_exit(void);
int		*stack_to_array(t_stack *a);
void	assign_index_by_sort(t_stack *a);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	sa(t_stack *a);
void	rra(t_stack *a);
void	radix_sort(t_stack *a, t_stack *b);
int		is_sorted(t_stack *s);
void	sort_three(t_stack *a);
void	sort_four_five(t_stack *a, t_stack *b);

#endif
