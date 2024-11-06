/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:29:08 by yohatana          #+#    #+#             */
/*   Updated: 2024/09/24 22:03:38 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include <math.h>

#include <X11/X.h>
#include <X11/keysym.h>

#include <stdio.h>

// int	close(int keycode, t_vars *vars);

// enum
enum
{
	ON_DESTROY = 17
};

typedef struct	s_player
{
	void	*img;
	int		img_width;
	int		img_height;
	char	*addr;
	char	*path;
	int		player_x;
	int		player_y;
}	t_player;

typedef	struct	s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;
	char	*addr;
	t_player	player;
}	t_vars;

int	key_hook(int keycode, t_vars *vars);
int	mouse_hook(int mouse_code, t_vars *vars);

int on_destroy(t_vars *vars)
{
	// ただ閉じるだけ
	// mlx_destroy_window(vars->mlx, vars->win);
	// mlx_destroy_display(vars->mlx);
	// free(vars);
	exit(0);
	return (0);
}

// 1ループを何フレームに設定する必要があるのか？
int	render_next_frame(t_vars vars)
{
	return (0);
}

int	print(t_vars vars, int keysym)
{
	(void)vars; // norm避け
	printf("press key: %d \n", keysym);
	return (0);

}

// void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

int	main(void)
{
	t_vars		vars;
	char		*path;
	t_player	player;

	vars.player = player;
	path = "./textures/onigiri_yakionigiri.xpm";
	vars.player.path = "./textures/MiConv.com__figure_hashiru.xpm";

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello");

	// キーボードの何かを押すとprint()が実行される
	// mlx_hook(vars.win, KeyPress, KeyPressMask, &print, &vars);

	// 左上のバツボタンを押したとき
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, &on_destroy, &vars);

	// キーボードのイベントが発生したときに呼び出される関数を設定する
	mlx_key_hook(vars.win, &key_hook, &vars);
	printf("player_x: %d player_y: %d\n", vars.player.player_x, vars.player.player_y);

	// マウスの入力に対するイベント
	mlx_mouse_hook(vars.win, mouse_hook, &vars);

	// 画像を保持する
	vars.img = mlx_xpm_file_to_image(vars.mlx, path, &vars.img_width, &vars.img_height);
	vars.player.img = mlx_xpm_file_to_image(vars.mlx, vars.player.path, &vars.player.img_width, &vars.player.img_height);
	if (!vars.player.img)
		printf("vars.player.img is NULL \n");

	// windowに画像を表示する
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	// 画像の透過ができない・・・透過処理が別に必要？

	mlx_put_image_to_window(vars.mlx, vars.win, vars.player.img, 0, 0);

	// 指定したフレームごとに描画する?
	// 1ループに対して行われるイベント
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);

	mlx_loop(vars.mlx);
	printf("player_x: %d player_y: %d\n", vars.player.player_x, vars.player.player_y);
	return (0);
}

//　キーボードが押されたときに実際に何が起きるか
int	key_hook(int keycode, t_vars *vars)
{
	// esc
	// printf("%d \n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
	if (keycode == 65362)
	{
		printf("push up\n");
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player.img, vars->player.player_x, vars->player.player_y + 25);
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
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->img_width, vars->img_height);
	}
	return (0);
}

int	mouse_hook(int mouse_code, t_vars *vars)
{
	printf("%d \n", mouse_code);
	int	left = 1;
	int	right = 3;
	int	midlle = 2;
	int	up = 4;
	int	down = 5;

	return (0);
}
