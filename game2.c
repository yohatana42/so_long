/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somukaid <somukaid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:05:29 by somukaid          #+#    #+#             */
/*   Updated: 2024/12/07 02:35:54 by somukaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	esckey_push(t_data *data)
{
	frees(data);
	mlx_destroy_image(data->mlx_ptr, data->img[0]);
	mlx_destroy_image(data->mlx_ptr, data->img[1]);
	mlx_destroy_image(data->mlx_ptr, data->img[2]);
	mlx_destroy_image(data->mlx_ptr, data->img[3]);
	mlx_destroy_image(data->mlx_ptr, data->img[4]);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

void	leftkey_push(t_data *data, size_t *move)
{
	if (data->map[data->player_y][data->player_x - 1] != 1)
	{
		data->player_x -= 1;
		++(*move);
	}
	if (data->player_x <= 0)
		data->player_x = 0;
}

void	rightkey_push(t_data *data, size_t *move)
{
	if (data->map[data->player_y][data->player_x + 1] != 1)
	{
		data->player_x += 1;
		++(*move);
	}
	if (data->player_x >= (data->map_x - 1))
		data->player_x = (data->map_x - 1);
}

void	upkey_push(t_data *data, size_t *move)
{
	if (data->map[data->player_y - 1][data->player_x] != 1)
	{
		data->player_y -= 1;
		++(*move);
	}
	if (data->player_y <= 0)
		data->player_y = 0;
}

void	downkey_push(t_data *data, size_t *move)
{
	if (data->map[data->player_y + 1][data->player_x] != 1)
	{
		data->player_y += 1;
		++(*move);
	}
	if (data->player_y >= (data->map_y - 1))
		data->player_y = (data->map_y - 1);
}
