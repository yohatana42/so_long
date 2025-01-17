/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:43:22 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/17 12:38:00 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	set_img(t_struct_all *all);
// // int on_destroy(t_struct_all *all);
// int	key_hook(int keycode, t_game *mlx);

int	render_next_frame(t_game *mlx);
int	print(t_game *mlx, int keysym);
void	print_img(t_struct_all *all);
int	print_wall(t_struct_all *all);

// 1ループを何フレームに設定する必要があるのか？
int	render_next_frame(t_game *mlx)
{
	(void)mlx; // norm避け
	return (0);
}

int	print(t_game *mlx, int keysym)
{
	(void)mlx; // norm避け
	printf("press key: %d \n", keysym);
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
	// mlx_key_hook(all->game->win, &key_hook, all->game);
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
	// print_wall
	print_wall(all);
	mlx_put_image_to_window(all->game->mlx, all->game->win, all->game->game_img->floor, 50, 50);
}

int	print_wall(t_struct_all *all)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < all->map->hight)
	{
		while (all->map->map_str[y][x] != '\0')
		{
			if (all->map->map_str[y][x] == '1')
			{
				mlx_put_image_to_window(all->game->mlx, all->game->win, \
							all->game->game_img->wall, x * IMG_W, y * IMG_H);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
