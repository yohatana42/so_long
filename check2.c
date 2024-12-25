/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somukaid <somukaid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:33:18 by somukaid          #+#    #+#             */
/*   Updated: 2024/12/19 03:57:05 by somukaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check(char *argv[], t_data *data)
{
	t_mapc	mapc;
	int		i;
	int		j;
	int		ret;

	ret = (is_openmap(argv[1], &mapc) || is_mapxsize(data, &mapc));
	if (ret == 1)
		return (1);
	ret = (is_squarecheck(&mapc) || is_mapysize(data, &mapc));
	if (ret == 1)
		return (1);
	ret = map_alloc(data, &mapc, &i, argv[1]);
	if (1 == ret)
		return (1);
	load_map(data, &mapc, &i, &j);
	ret = can_playing(data, &i, &j);
	if (1 == ret)
		return (1);
	is_wall(data);
	is_3piece(data);
	return (0);
}

void	move(int x, int y, t_data *data)
{
	if (x < 0 || data->map_x <= x || y < 0 || data->map_y <= y \
		|| data->map[y][x] != 0)
		return ;
	data->map[y][x] = 5;
	move(x - 1, y, data);
	move(x + 1, y, data);
	move(x, y - 1, data);
	move(x, y + 1, data);
}

void	move_r(int x, int y, t_data *data)
{
	if (x < 0 || data->map_x <= x || y < 0 || data->map_y <= y \
		|| data->map[y][x] != 5)
		return ;
	data->map[y][x] = 0;
	move_r(x - 1, y, data);
	move_r(x + 1, y, data);
	move_r(x, y - 1, data);
	move_r(x, y + 1, data);
}

void	is_wall(t_data *data)
{
	size_t	i;
	int		check;

	check = 0;
	i = 0;
	while (i < (size_t)data->map_x)
	{
		if (data->map[0][i] != 1 || data->map[data->map_y - 1][i] != 1)
			check = 1;
		++i;
	}
	i = 0;
	while (i < (size_t)data->map_y)
	{
		if (data->map[i][0] != 1 || data->map[i][data->map_x - 1] != 1)
			check = 1;
		++i;
	}
	if (check == 1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("error_no_wall\n", 2);
		frees(data);
		exit (1);
	}
}

void	is_3piece(t_data *data)
{
	int	check;

	check = 0;
	if (data->player != 1)
		check = 1;
	if (data->collect == 0)
		check = 1;
	if (data->end != 1)
		check = 1;
	if (check == 1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("error_check_items\n", 2);
		frees(data);
		exit (1);
	}
}
