#include <unistd.h>

int	print_error(void)
{
	write(1, "Error\n", 6);
	return (-1);
}

void	print_map(int **map, int len_line)
{
	int		x;
	int		y;
	char	buf[9 * 2 + 1];

	y = 0;
	while (y < len_line)
	{
		x = 0;
		while (x < len_line)
		{
			buf[x] = '0' + map[y][x];
			buf[x + 1] = ' ';
			++x;
		}
		buf[x] = '\n';
		write(1, buf, len_line * 2 + 1);
		++y;
	}
}