/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:43:22 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/15 21:48:50 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	set_img(t_map *map, t_game *mlx);
// // int on_destroy(t_struct_all *all);
// int	key_hook(int keycode, t_game *mlx);

int	key_hook(int keycode, t_struct_all *all);
int	render_next_frame(t_game *mlx);
int	print(t_game *mlx, int keysym);
void	print_img(t_map *map, t_game *game);

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

	// 画像をセット
	// result = set_img(all->map, all->game);

	// 画像表示
	// print_img(all->map, all->game);

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

int	set_img(t_map *map, t_game *game)
{
	(void)map;
	int	h;
	int	w;

	h = IMG_H;
	w = IMG_W;
	game->game_img->wall = mlx_xpm_file_to_image(game->mlx, \
							"./textures/pattern_uroko.xpm", &h, &w);
	// game->game_img->exit = mlx_xpm_file_to_image(game->mlx, \
	// 						"texture/path", IMG_H, IMG_W);
	// game->game_img->collect = mlx_xpm_file_to_image(game->mlx, \
	// 						"texture/path", IMG_H, IMG_W);
	// game->game_img->wall = mlx_xpm_file_to_image(game->mlx, \
	// 						"texture/path", IMG_H, IMG_W);
	game->game_img->floor = mlx_xpm_file_to_image(game->mlx, \
							"./textures/pattern_shibafu.xpm", &h, &w);
	return (0);
}

void	print_img(t_map *map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->hight)
	{
		while (map->map_str[i][j] != '\0')
		{
			// if (map->map_str[i][j] == '1')
			// {

			// }
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->game_img->wall, 100, 100);
	mlx_put_image_to_window(game->mlx, game->win, game->game_img->floor, 50, 50);
}

//　キーボードが押されたときに実際に何が起きるか
int	key_hook(int keycode, t_struct_all *all)
{
	// esc
	// printf("%d \n", keycode);
	if (keycode == 65307)
	{
		free_struct_all(all);
		exit(0);
	}
	if (keycode == 65362)
	{
		printf("push up\n");
		// 行き先が壁の場合は立ち止まる
		// 出口に乗っかった場合
			// すべての収集物を撮ってない場合
			// すべての収集物を集めた場合
			// mlx_string_put();
		// mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player.img, mlx->player.player_x, mlx->player.player_y + 25);
	}
	if (keycode == 65363)
	{
		printf("push right\n");
	}
	if (keycode == 65361)
	{
		printf("push left\n");
	}
	if (keycode == 65364)
	{
		printf("push down\n");
	}
	if (keycode == 97)
	{
		printf("push a\n");
	}
	if (keycode == 115)
	{
		printf("push s\n");
	}
	if (keycode == 119)
	{
		printf("push w\n");
	}
	if (keycode == 100)
	{
		printf("push d\n");
		// mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, mlx->img_width, mlx->img_height);
	}
	return (0);
}
