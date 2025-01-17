/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:43:22 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/17 20:36:15 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	set_img(t_struct_all *all);

int	game_init(t_struct_all *all)
{
	int	win_w;
	int	win_h;

	win_w = IMG_W * all->map->width;
	win_h = IMG_H * all->map->hight;
	all->game->mlx = mlx_init();
	all->game->win = mlx_new_window(all->game->mlx, win_w, win_h, "so_long");
	set_img(all);
	print_img(all);
	mlx_hook(all->game->win, DestroyNotify, \
				StructureNotifyMask, on_destroy, all);
	mlx_key_hook(all->game->win, &key_hook, all);
	mlx_loop(all->game->mlx);
	return (0);
}

int	set_img(t_struct_all *all)
{
	int	h;
	int	w;

	h = IMG_H;
	w = IMG_W;
	all->game->game_img->wall = mlx_xpm_file_to_image(all->game->mlx, \
							"./textures/book_shell.xpm", &h, &w);
	all->game->game_img->exit = mlx_xpm_file_to_image(all->game->mlx, \
							"./textures/door.xpm", &h, &w);
	all->game->game_img->collect = mlx_xpm_file_to_image(all->game->mlx, \
							"./textures/book.xpm", &h, &w);
	all->game->game_img->player = mlx_xpm_file_to_image(all->game->mlx, \
							"./textures/witch.xpm", &h, &w);
	all->game->game_img->floor = mlx_xpm_file_to_image(all->game->mlx, \
							"./textures/floor.xpm", &h, &w);
	return (0);
}
