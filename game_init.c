/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:43:22 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/12 14:00:55 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	set_img(t_map *map, t_mlx *mlx);
void	print_img(t_map *map, t_mlx *mlx);
int on_destroy(t_mlx *mlx);
int	key_hook(int keycode, t_mlx *mlx);
int	render_next_frame(t_mlx *mlx);
int	print(t_mlx *mlx, int keysym);

t_mlx	*create_mlx_struct(void);

int on_destroy(t_mlx *mlx)
{
	// ただ閉じるだけ
	printf("on_destroy\n");
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx);
	// exit(0);
	return (0);
}

// 1ループを何フレームに設定する必要があるのか？
int	render_next_frame(t_mlx *mlx)
{
	(void)mlx; // norm避け
	return (0);
}

int	print(t_mlx *mlx, int keysym)
{
	(void)mlx; // norm避け
	printf("press key: %d \n", keysym);
	return (0);

}

int	game_init(t_map *map)
{
	//TODO
	/*
	・ウィンドウの構造体を作る
	・imgをおのおの用意する
	*/

	t_mlx *mlx;
	int		result;

	mlx = create_mlx_struct();

	// 画像をセット
	result = set_img(map, mlx);

	// 画像表示
	// void	print_img(map, mlx);
	// mlx_put_image_to_window(mlx->mlx, mlx->win, map->player->img, 0, 0);

	// 左上のバツボタンを押したとき
	mlx_hook(mlx->win, DestroyNotify, StructureNotifyMask, on_destroy, mlx);

	// 終了処理
	// mlx_destroy_display(mlx->mlx);
	// mlx_destroy_window(mlx->mlx, mlx->win);

	// キーボードのイベントが発生したときに呼び出される関数を設定する
	mlx_key_hook(mlx->win, &key_hook, mlx);

	// こいつに入ると何もできんくなるらしい
	mlx_loop(mlx->mlx);
	return (0);
}

int	set_img(t_map *map, t_mlx *mlx)
{

	// wall img set
	mlx->wall->path = "";
	mlx->wall->img_h = 10;
	mlx->wall->img_w = 10;
	mlx->wall->img = mlx_xpm_file_to_image(mlx->mlx, mlx->wall->path, &mlx->wall->img_h, &mlx->wall->img_w);
	mlx->space->path = "";
	mlx->space->img_h = 10;
	mlx->space->img_w = 10;
	mlx->space->img = mlx_xpm_file_to_image(mlx->mlx, mlx->space->path, &mlx->space->img_h, &mlx->space->img_w);

	map->player->path = "./textures/MiConv.com__figure_hashiru.xpm";
	map->player->img_w = 10;
	map->player->img_h = 10;
	map->player->img = mlx_xpm_file_to_image(mlx->mlx, map->player->path, &map->player->img_h, &map->player->img_w);

	map->exit->path = "./textures/MiConv.com__figure_hashiru.xpm";
	map->exit->img_w = 10;
	map->exit->img_h = 10;
	map->exit->img = mlx_xpm_file_to_image(mlx->mlx, map->player->path, &map->player->img_h, &map->player->img_w);

	// collectの数だけ構造体がある　一個一個にimg入れるのは現実的ではない
	map->player->img = mlx_xpm_file_to_image(mlx->mlx, map->player->path, &map->player->img_h, &map->player->img_w);
	return (0);
}

void	print_img(t_map *map, t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, map->player->img, 0, 0);
}

//　キーボードが押されたときに実際に何が起きるか
int	key_hook(int keycode, t_mlx *mlx)
{
	// esc
	// printf("%d \n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
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
		printf("push left\n");
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
