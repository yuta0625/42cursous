/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:04:53 by yohya             #+#    #+#             */
/*   Updated: 2025/12/14 18:11:57 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
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
void	fill_stack_from_args(int argc, char **argv, t_stack *a);
void	print_stack(t_stack *s, const char *name);
int		is_valid_integer_string(char *s);
int		to_number_with_check(char *s, int *out);
int		is_duplicate_in_stack(t_stack *a, int value);
void	error_and_exit(void);
int		*stack_to_array(t_stack *a);
void	check_duplicates_sorted(int *arr, int n);
void	assign_index_by_sort(t_stack *a);
void	ft_swap(int *a, int *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	radix_sort(t_stack *a, t_stack *b);

#endif
