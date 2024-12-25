/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somukaid <somukaid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:05:29 by somukaid          #+#    #+#             */
/*   Updated: 2024/12/19 02:10:23 by somukaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_map(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->map_y)
	{
		i = 0;
		while (i < data->map_x)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
				data->img[(data->map[j][i])], i * 50, j * 50);
			++i;
		}
		++j;
	}
}

int	print_stage(t_data *data)
{
	static size_t	n = 0;

	if (data->map[data->player_y][data->player_x] == 2)
	{
		data->map[data->player_y][data->player_x] = 0;
		--(data->collect);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	make_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img[4], data->player_x * 50, data->player_y * 50);
	++n;
	if (n == 60000)
		n = 0;
	return (0);
}

int	is_goal(t_data *data)
{
	static size_t	n = 0;

	if (n % 10 == 0)
	{
		if (data->map[data->player_y][data->player_x] == 2)
		{
			data->map[data->player_y][data->player_x] = 0;
			--(data->collect);
		}
		if (data->map[data->player_y][data->player_x] == 3)
		{
			if (data->collect == 0 && n % 100 == 0)
			{
				printf("CLEAR!!\n");
				sleep(3);
				esckey_push(data);
			}
			else if (data->collect != 0)
				printf("You need %ld flags!!\n", data->collect);
		}
	}
	++n;
	if (n == 60000)
		n = 0;
	return (0);
}

int	keyboad_push(int key, t_data *data)
{
	static size_t	move;
	size_t			mem;

	printf("%d\n", key);
	mem = move;
	if (key == ESC_KEY)
		esckey_push(data);
	if (key == LEFT_KEY || key == A_KEY)
		leftkey_push(data, &move);
	else if (key == RIGHT_KEY || key == D_KEY)
		rightkey_push(data, &move);
	else if (key == UP_KEY || key == W_KEY)
		upkey_push(data, &move);
	else if (key == DOWN_KEY || key == S_KEY)
		downkey_push(data, &move);
	if (mem != move)
		printf("Your stap is %ld\n", move);
	print_stage(data);
	return (0);
}

void	frees(t_data *data)
{
	int	i;

	i = 0;
	while (NULL != data->map[i])
	{
		free(data->map[i]);
		++i;
	}
	if (NULL != data->map)
		free(data->map);
}
