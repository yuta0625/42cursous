/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:32:53 by rynitta           #+#    #+#             */
/*   Updated: 2025/09/14 16:11:41 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int		is_valid_args(int argc, char **argv);
int		ft_atoi(char *str);
int		find_answer(int map[][9], int len_line, int num_viewable_box[][9]);
int		print_error(void);
void	print_map(int map[][9], int len_line);
int		find_answer(int map[][9], int len_line, int num_viewable_box[][9]);
int		count_arrays(char **array_str);
char	**ft_split(char *s, char c);
void	free_str_args(char **array_str);
int		check_all_row_pattern(int map[][9], int len_line, \
	int num_viewable_box[][9], int i_row);

#define DIRECTION_COL_TOP	0
#define DIRECTION_COL_BOTTOM	1
#define DIRECTION_ROW_LEFT 2
#define DIRECTION_ROW_RIGHT 3
#define OK 0
#define NG -1
#define SUCCESS 0
#define FAIL -1

void	set_num_viewable_box(int num_viewable_box[][9], \
	int len_line, char **argv)
{
	int	direction_;
	int	i;

	direction_ = 0;
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

int	find_answer(int map[][9], int len_line, int num_viewable_box[][9])
{
	return (check_all_row_pattern(map, len_line, num_viewable_box, 0));
}

int	main(int argc, char **argv)
{
	int	map[9][9];
	int	len_line;
	int	num_viewable_box[4][9];

	if (argc != 2)
		return (print_error());
	argv = ft_split(argv[1], ' ');
	if (!argv)
		return (print_error());
	argc = count_arrays(argv);
	if (!is_valid_args(argc, argv))
		return (print_error());
	len_line = argc / 4;
	set_num_viewable_box(num_viewable_box, len_line, argv);
	free_str_args(argv);
	if (find_answer(map, len_line, num_viewable_box) == SUCCESS)
	{
		print_map(map, len_line);
		return (0);
	}
	else
		return (print_error());
}
