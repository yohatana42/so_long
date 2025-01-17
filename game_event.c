/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:33:09 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/17 14:14:15 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	on_destroy(t_struct_all *all)
{
	// ただ閉じるだけ
	printf("on_destroy\n");
	mlx_loop_end(all->game->mlx);
	free_struct_all(all);
	exit(0);
	return (0);
}

//　キーボードが押されたときに実際に何が起きるか
int	key_hook(int keycode, t_struct_all *all)
{
	// esc
	// printf("%d \n", keycode);
	if (keycode == ESC)
	{
		mlx_loop_end(all->game->mlx);
		free_struct_all(all);
		exit(0);
	}
	if (keycode == UP)
	{
		printf("push up\n");
		// 行き先が壁の場合は立ち止まる
		// 出口に乗っかった場合
			// すべての収集物を撮ってない場合
			// すべての収集物を集めた場合
			// mlx_string_put();
		// mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player.img, mlx->player.player_x, mlx->player.player_y + 25);
	}
	if (keycode == RIGHT)
	{
		printf("push right\n");
	}
	if (keycode == LEFT)
	{
		printf("push left\n");
	}
	if (keycode == DOWN)
	{
		printf("push down\n");
	}
	if (keycode == A)
	{
		printf("push a\n");
	}
	if (keycode == S)
	{
		printf("push s\n");
	}
	if (keycode == W)
	{
		printf("push w\n");
	}
	if (keycode == D)
	{
		printf("push d\n");
		// mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, mlx->img_width, mlx->img_height);
	}
	return (0);
}
