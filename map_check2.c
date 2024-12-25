/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somukaid <somukaid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 06:52:15 by somukaid          #+#    #+#             */
/*   Updated: 2024/12/19 04:01:27 by somukaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_alloc(t_data *data, t_mapc *mapc, int *i, char *argv)
{
	*i = 0;
	data->map = (int **)malloc(sizeof(int *) * (data->map_y + 1));
	if (NULL == data->map)
		return (1);
	while (*i < data->map_y)
	{
		data->map[*i] = (int *)malloc(sizeof(int) * data->map_x);
		if (NULL == data->map[*i])
		{
			--(*i);
			while (*i >= 0)
			{
				free(data->map[*i]);
				--(*i);
			}
			free(data->map);
			return (1);
		}
		++(*i);
	}
	data->map[*i] = NULL;
	mapc->fd = open(argv, O_RDONLY);
	return (0);
}

void	load_map(t_data *data, t_mapc *mapc, int *i, int *j)
{
	*j = 0;
	while (*j < data->map_y)
	{
		mapc->line = get_next_line(mapc->fd);
		*i = 0;
		while (*i < data->map_x)
		{
			alpha_to_mapint(data, mapc, i, j);
		}
		free(mapc->line);
		*i = 0;
		++(*j);
	}
	mapc->line = NULL;
}

int	can_playing(t_data *data, int *i, int *j)
{
	move(data->player_x, data->player_y, data);
	*j = 0;
	while (*j < data->map_y)
	{
		*i = 0;
		while (*i < data->map_x)
		{
			if (data->map[*j][*i] == 2 || data->map[*j][*i] == 3)
			{
				if (data->map[(*j) - 1][*i] == 0 || \
					data->map[*j][(*i) - 1] == 0 || \
					data->map[(*j) + 1][*i] == 0 || \
					data->map[*j][(*i) + 1] == 0)
				{
					ft_putstr_fd("Error\n", 2);
					ft_putstr_fd("this map is not playing\n", 2);
					return (frees(data), 1);
				}
			}
			++(*i);
		}
		++(*j);
	}
	move_r(data->player_x, data->player_y, data);
	return (0);
}
