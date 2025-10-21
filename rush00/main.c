int	is_valid_args(int argc, char **argv);
int	ft_atoi(char *str);
int	find_answer(int **map, int len_line, int **num_viewable_box);
int	print_error();
void	print_map(int **map, int len_line);
int	find_answer(int **map, int len_line, int **num_viewable_box);

#include <stdbool.h>

#define DIRECTION_COL_TOP	(0)
#define DIRECTION_COL_BOTTOM	(1)
#define DIRECTION_ROW_LEFT (2)
#define DIRECTION_ROW_RIGHT (3)
# define OK (0)
#define NG (-1)
#define SUCCESS (0)
#define FAIL (-1)

void	set_num_viewable_box(int **num_viewable_box, int len_line, char **argv)
{
	int	direction_;
	int	i;

	direction_ = 0;
	++argv;
	while (direction_ < 4)
	{
		i = 0;
		while (i < len_line)
		{
			num_viewable_box[direction_][i] = ft_atoi(*argv);
			++argv;
			++i;
		}
		++direction_;
	}
}

int main(int argc, char **argv)
{
	int	map[9][9];
	int	len_line;
	int	num_viewable_box[4][9];

	if (!is_valid_args(argc, argv))
		return (print_error());
	len_line = (argc - 1) / 4;
	set_num_viewable_box((int **)num_viewable_box, len_line, argv);
	if (find_answer((int **)map, len_line, (int **)num_viewable_box) == SUCCESS)
	{
		print_map((int **)map, len_line);
		return (0);
	}
	else
		return (print_error());
}
