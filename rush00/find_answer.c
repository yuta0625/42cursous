#define DIRECTION_COL_TOP	(0)
#define DIRECTION_COL_BOTTOM	(1)
#define DIRECTION_ROW_LEFT (2)
#define DIRECTION_ROW_RIGHT (3)
#define OK (0)
#define NG (-1)
#define SUCCESS (0)
#define FAIL (-1)

#include <stdbool.h>

bool	is_valid_row(int **map, int len_line, int **num_viewable_box, int i_row);
bool	is_valid_map(int **map, int len_line, int **num_viewable_box);
int	ft_swap(int	*a, int *b);
int	ft_reverse(int *array, int size);

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

int	check_all_row_pattern(int **map, int len_line, int **num_viewable_box, int i_row)
{
	int	i;

	if (i_row == len_line)
	{
		if (is_valid_map(map, len_line, num_viewable_box))
			return (SUCCESS);
		else
			return (FAIL);
	}
	i = 0;
	while (i < len_line)
		map[i_row][i] = i + 1;
	if (check_all_row_pattern(map, len_line, num_viewable_box, i_row + 1) == SUCCESS)
		return (SUCCESS);
	while (set_next_pattern(map[i_row], len_line) == SUCCESS)
	{
		if (check_all_row_pattern(map, len_line, num_viewable_box, i_row + 1) == SUCCESS)
			return (SUCCESS);
	}
	return (FAIL);
}

int	find_answer(int **map, int len_line, int **num_viewable_box)
{
	return (check_all_row_pattern(map, len_line, num_viewable_box, 0));
}


// #include <stdio.h>

// int main()
// {
// 	int	row[] = {0, 1, 2, 3, 4};
// 	while (set_next_pattern(row, 5) == SUCCESS)
// 	{
// 		for (int i = 4; i >= 0; --i)
// 			printf("%d ", row[i]);
// 		printf("\n");
// 	}
// }

// 0 1 2 3 4

// 1 0 2 3 4

// 0 2 1 3 4

// 2 0 1 3 4

// 1 2 0 3 4


// 4 3 2 1 0

// 3 4 2 1 0

// 4 2 3 1 0




// 0 1 2 3 4

// 0 1 2 4 3

// 0 1 3 2 4

// 0 1 3 4 2

// 0 1 4 2 3

// 0 1 4 3 2

// 0 2 1 3 4

// 0 2 1 4 3

// 0 2 

// 3 4 5 2 1

// 3 5 1 2 4
