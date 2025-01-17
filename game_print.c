/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:16:17 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/17 20:21:07 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static int	print_wall_and_floor(t_struct_all *all);

void	print_img(t_struct_all *all)
{
	print_wall_and_floor(all);
	print_collect(all);
	mlx_put_image_to_window(all->game->mlx, all->game->win, \
							all->game->game_img->exit, \
							all->game->exit->x * IMG_W, \
							all->game->exit->y * IMG_H);
	mlx_put_image_to_window(all->game->mlx, all->game->win, \
							all->game->game_img->player, \
							all->game->player->x * IMG_W, \
							all->game->player->y * IMG_H);
}

int	print_collect(t_struct_all *all)
{
	t_collect	*collect;

	collect = *(all->game->c_list);
	while (collect)
	{
		if (collect->get_flg == 0)
		{
			mlx_put_image_to_window(all->game->mlx, all->game->win, \
										all->game->game_img->collect, \
										collect->x * IMG_W, collect->y * IMG_H);
		}
		else
		{
			mlx_put_image_to_window(all->game->mlx, all->game->win, \
										all->game->game_img->floor, \
										collect->x * IMG_W, collect->y * IMG_H);
		}
		collect = collect->next;
	}
	return (0);
}

void	print_player(t_struct_all *all, int cur_x, int cur_y)
{
	mlx_put_image_to_window(all->game->mlx, all->game->win, \
						all->game->game_img->floor, \
						cur_x * IMG_W, cur_y * IMG_H);
	mlx_put_image_to_window(all->game->mlx, all->game->win, \
						all->game->game_img->exit, \
						all->game->exit->x * IMG_W, all->game->exit->y * IMG_H);
	mlx_put_image_to_window(all->game->mlx, all->game->win, \
						all->game->game_img->player, \
						all->game->player->x * IMG_W, \
						all->game->player->y * IMG_H);
}

static int	print_wall_and_floor(t_struct_all *all)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < all->map->hight)
	{
		while (all->map->map_str[y][x] != '\0')
		{
			if (all->map->map_str[y][x] == WALL)
			{
				mlx_put_image_to_window(all->game->mlx, all->game->win, \
							all->game->game_img->wall, x * IMG_W, y * IMG_H);
			}
			else if (all->map->map_str[y][x] == FLOOR)
			{
				mlx_put_image_to_window(all->game->mlx, all->game->win, \
							all->game->game_img->floor, x * IMG_W, y * IMG_H);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
