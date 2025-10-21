#define DIRECTION_COL_TOP	(0)
#define DIRECTION_COL_BOTTOM	(1)
#define DIRECTION_ROW_LEFT (2)
#define DIRECTION_ROW_RIGHT (3)
#define OK (0)
#define NG (-1)

#include <stdbool.h>
bool	is_valid_row(int **map, int len_line, int **num_viewable_box, int i_row);

static int	_check_col_direction_top(int **map, int len_line, int **num_viewable_box, int i_col)
{
	int	count_viewable_box_;
	int	current_max_height_;
	int	i_row;

	current_max_height_ = 0;
	i_row = 0;
	while (i_row < len_line)
	{
		if (current_max_height_ < map[i_row][i_col])
		{
			current_max_height_ = map[i_row][i_col];
			++count_viewable_box_;
		}
		++i_row;
	}
	if (count_viewable_box_ == num_viewable_box[DIRECTION_COL_TOP][i_col])
		return (OK);
	else
		return (NG);
}

static int	_check_col_direction_bottom(int **map, int len_line, int **num_viewable_box, int i_col)
{
	int	count_viewable_box_;
	int	current_max_height_;
	int	i_row;

	current_max_height_ = 0;
	i_row = len_line - 1;
	while (i_row >= 0)
	{
		if (current_max_height_ < map[i_row][i_col])
		{
			current_max_height_ = map[i_row][i_col];
			++count_viewable_box_;
		}
		--i_row;
	}
	if (count_viewable_box_ == num_viewable_box[DIRECTION_COL_BOTTOM][i_col])
		return (OK);
	else
		return (NG);
}

static int	_is_unique_height(int **map, int len_line, int i_col)
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
		if (is_used_[map[i][i_col]] == true)
			return (false);
		else
			is_used_[map[i][i_col]] = true;
		++i;
	}
	return (true);
}

bool	is_valid_col(int **map, int len_line, int **num_viewable_box, int i_col)
{

	if (_is_unique_height(map, len_line, i_col) == false \
		|| _check_col_direction_top(map, len_line, num_viewable_box, i_col) == NG \
		|| _check_col_direction_bottom(map, len_line, num_viewable_box, i_col) == NG)
		return (false);
	return (true);
}

bool	is_valid_map(int **map, int len_line, int **num_viewable_box)
{
	int	i;

	i = 0;
	while (i < len_line)
	{
		if (is_valid_row(map, len_line, num_viewable_box, i) == false \
			|| is_valid_col(map, len_line, num_viewable_box, i) == false)
			return (false);
	}
	return (true);
}