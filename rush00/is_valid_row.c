#define DIRECTION_COL_TOP	(0)
#define DIRECTION_COL_BOTTOM	(1)
#define DIRECTION_ROW_LEFT (2)
#define DIRECTION_ROW_RIGHT (3)
#define OK (0)
#define NG (-1)

#include <stdbool.h>

static int	_check_row_direction_left(int **map, int len_line, int **num_viewable_box, int i_row)
{
	int	count_viewable_box_;
	int	current_max_height_;
	int	i_col;

	current_max_height_ = 0;
	i_col = 0;
	while (i_col < len_line)
	{
		if (current_max_height_ < map[i_row][i_col])
		{
			current_max_height_ = map[i_row][i_col];
			++count_viewable_box_;
		}
		++i_col;
	}
	if (count_viewable_box_ == num_viewable_box[DIRECTION_ROW_LEFT][i_row])
		return (OK);
	else
		return (NG);
}

static int	_check_row_direction_right(int **map, int len_line, int **num_viewable_box, int i_row)
{
	int	count_viewable_box_;
	int	current_max_height_;
	int	i_col;

	current_max_height_ = 0;
	i_col = len_line - 1;
	while (i_col < len_line)
	{
		if (current_max_height_ < map[i_row][i_col])
		{
			current_max_height_ = map[i_row][i_col];
			++count_viewable_box_;
		}
		--i_col;
	}
	if (count_viewable_box_ == num_viewable_box[DIRECTION_ROW_RIGHT][i_row])
		return (OK);
	else
		return (NG);
}

static int	_is_unique_height(int **map, int len_line, int i_row)
{
	bool	is_used_[10];
	int	i;

	i = 1;
	while (i <= len_line)
	{
		is_used_[i] = false;
		++i;
	}
	i = 0;
	while (i < len_line)
	{
		if (is_used_[map[i_row][i]] == true)
			return (false);
		else
			is_used_[map[i_row][i]] = true;
		++i;
	}
	return (true);
}

bool	is_valid_row(int **map, int len_line, int **num_viewable_box, int i_row)
{
	if (_is_unique_height(map, len_line, i_row) == false
		|| _check_row_direction_left(map, len_line, num_viewable_box, i_row) == NG \
		|| _check_row_direction_right(map, len_line, num_viewable_box, i_row) == NG)
		return (false);
	return (true);
}
