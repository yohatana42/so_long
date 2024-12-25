/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somukaid <somukaid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 06:41:23 by somukaid          #+#    #+#             */
/*   Updated: 2024/12/19 04:03:29 by somukaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_openmap(char *argv, t_mapc *mapc)
{
	mapc->fd = open(argv, O_RDONLY);
	if (mapc->fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("error_ber.file_is_not_open\n", 2);
		return (1);
	}
	return (0);
}

int	is_mapxsize(t_data *data, t_mapc *mapc)
{
	mapc->count = 0;
	mapc->line = get_next_line(mapc->fd);
	data->map_x = ft_strlen(mapc->line) - 1;
	if (data->map_x <= 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("error_too_short_map_x_size\n", 2);
		free(mapc->line);
		return (1);
	}
	return (0);
}

int	is_squarecheck(t_mapc *mapc)
{
	while (mapc->line != NULL)
	{
		++(mapc->count);
		mapc->len = ft_strlen(mapc->line);
		free(mapc->line);
		mapc->line = get_next_line(mapc->fd);
		if (mapc->len != ft_strlen(mapc->line) && mapc->line != NULL)
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("error_map_is_not_square\n", 2);
			free(mapc->line);
			return (1);
		}
	}
	close(mapc->fd);
	return (0);
}

int	is_mapysize(t_data *data, t_mapc *mapc)
{
	data->map_y = mapc->count;
	if (data->map_y <= 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("this map is not playing\n", 2);
		return (1);
	}
	return (0);
}

void	alpha_to_mapint(t_data *data, t_mapc *mapc, int *i, int *j)
{
	if (mapc->line[*i] == 'P')
	{
		data->player_x = *i;
		data->player_y = *j;
		data->map[*j][*i] = 0;
		++(data->player);
	}
	else if (mapc->line[*i] == 'C')
	{
		data->map[*j][*i] = 2;
		++(data->collect);
	}
	else if (mapc->line[*i] == 'E')
	{
		data->map[*j][*i] = 3;
		++(data->end);
	}
	else
		data->map[*j][*i] = mapc->line[*i] - '0';
	++(*i);
}
