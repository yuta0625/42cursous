/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_answer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 13:04:43 by rynitta           #+#    #+#             */
/*   Updated: 2025/09/14 16:11:59 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#define DIRECTION_COL_TOP	0
#define DIRECTION_COL_BOTTOM	1
#define DIRECTION_ROW_LEFT 2
#define DIRECTION_ROW_RIGHT 3
#define OK 0
#define NG -1
#define SUCCESS 0
#define FAIL -1

bool	is_valid_row(int map[][9], int len_line, \
	int num_viewable_box[][9], int i_row);
bool	is_valid_map(int map[][9], int len_line, int num_viewable_box[][9]);
int		ft_swap(int	*a, int *b);
int		ft_reverse(int *array, int size);

int	set_next_pattern(int *row, int len_line)
{
	int	i;
	int	j;

	i = 1;
	while (i < len_line)
	{
		if (row[i - 1] < row[i])
		{
			j = 0;
			while (j < i)
			{
				if (row[j] < row[i])
				{
					ft_swap(&row[j], &row[i]);
					ft_reverse(row, i);
					return (SUCCESS);
				}
				++j;
			}
		}
		++i;
	}
	return (FAIL);
}

static void	_initialize(int map[][9], int len_line, int i_row)
{
	int	i;

	i = 0;
	while (i < len_line)
	{
		map[i_row][i] = i + 1;
		++i;
	}
}

static int	_is_unique_height(int map[][9], int len_line, int i_col)
{
	bool	is_used_[10];
	int		i;

	i = 1;
	while (i <= 10)
	{
		is_used_[i] = false;
		++i;
	}
	i = 0;
	while (i < len_line)
	{
		if (is_used_[map[i][i_col]] == true)
			return (false);
		else
			is_used_[map[i][i_col]] = true;
		++i;
	}
	return (true);
}

static int	_is_all_col_unique_height(int map[][9], int len_line, \
	int current_len)
{
	int	i_col;

	i_col = 0;
	while (i_col < len_line)
	{
		if (!_is_unique_height(map, current_len, i_col))
			return (false);
		++i_col;
	}
	return (true);
}

int	check_all_row_pattern(int map[][9], int len_line, \
	int num_viewable_box[][9], int i_row)
{
	_initialize(map, len_line, i_row);
	if (i_row == len_line && is_valid_map(map, len_line, num_viewable_box))
		return (SUCCESS);
	else if (i_row == len_line \
		&& is_valid_map(map, len_line, num_viewable_box))
		return (FAIL);
	if (is_valid_row(map, len_line, num_viewable_box, i_row) \
		&& _is_all_col_unique_height(map, len_line, i_row + 1) \
		&& check_all_row_pattern(map, len_line, num_viewable_box, \
			i_row + 1) == SUCCESS)
		return (SUCCESS);
	while (set_next_pattern(map[i_row], len_line) == SUCCESS)
	{
		if (is_valid_row(map, len_line, num_viewable_box, i_row) \
			&& _is_all_col_unique_height(map, len_line, i_row + 1) \
			&& check_all_row_pattern(map, len_line, num_viewable_box, \
				i_row + 1) == SUCCESS)
			return (SUCCESS);
	}
	return (FAIL);
}

/*
#include <stdio.h>

int main()
{
	int	row[] = {0, 1, 2, 3, 4};
	while (set_next_pattern(row, 5) == SUCCESS)
	{
		for (int i = 4; i >= 0; --i)
			printf("%d ", row[i]);
		printf("\n");
	}
}

0 1 2 3 4

1 0 2 3 4

0 2 1 3 4

2 0 1 3 4

1 2 0 3 4


4 3 2 1 0

3 4 2 1 0

4 2 3 1 0




0 1 2 3 4

0 1 2 4 3

0 1 3 2 4

0 1 3 4 2

0 1 4 2 3

0 1 4 3 2

0 2 1 3 4

0 2 1 4 3

0 2 

3 4 5 2 1

3 5 1 2 4
*/