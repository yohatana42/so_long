/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:43:22 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/17 15:51:57 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	set_img(t_struct_all *all);
// // int on_destroy(t_struct_all *all);
// int	key_hook(int keycode, t_game *mlx);

int	render_next_frame(t_game *mlx);
void	print_img(t_struct_all *all);
static int	print_wall_and_floor(t_struct_all *all);
int	print_collect(t_struct_all *all);

// 1ループを何フレームに設定する必要があるのか？
int	render_next_frame(t_game *mlx)
{
	(void)mlx; // norm避け
	return (0);
}

int	game_init(t_struct_all *all)
{
	// int result = 0;
	int	win_w;
	int	win_h;

	win_w = IMG_W * all->map->width;
	win_h = IMG_H * all->map->hight;
	all->game->mlx = mlx_init();
	all->game->win = mlx_new_window(all->game->mlx, win_w, win_h, "so_long");

	set_img(all);

	print_img(all);

	// 左上のバツボタンを押したとき
	mlx_hook(all->game->win, DestroyNotify,
			StructureNotifyMask, on_destroy, all);

	// キーボードのイベントが発生したときに呼び出される関数を設定する
	mlx_key_hook(all->game->win, &key_hook, all);

	// こいつに入ると何もできんくなるらしい
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
