/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:04:53 by yohya             #+#    #+#             */
/*   Updated: 2025/12/16 10:06:57 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	quick_sort(int *arr, int left, int right)
{
	int	pivot;
	int	i;
	int	j;

	if (left >= right)
		return ;
	pivot = arr[(left + right) / 2];
	i = left;
	j = right;
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
			ft_swap(&arr[i++], &arr[j--]);
	}
	if (left < j)
		quick_sort(arr, left, j);
	if (i < right)
		quick_sort(arr, i, right);
}

static	int	get_rank_by_binary_search(int *arr, int size, int target)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] == target)
			return (mid);
		else if (arr[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

void	assign_index_by_sort(t_stack *a)
{
	int		*arr;
	t_node	*cur;
	int		i;
	int		pos;

	if (!a || a->size <= 0)
		return ;
	arr = stack_to_array(a);
	quick_sort(arr, 0, a->size - 1);
	cur = a->top;
	i = 0;
	while (i < a->size)
	{
		pos = get_rank_by_binary_search(arr, a->size, cur->value);
		if (pos < 0)
			error_and_exit();
		cur->index = pos;
		cur = cur->next;
		i++;
	}
	free(arr);
}
