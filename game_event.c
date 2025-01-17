/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:33:09 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/17 16:39:43 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	all_get_check(t_struct_all *all);

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
	int	post_x;
	int	post_y;

	post_x = all->game->player->x;
	post_y = all->game->player->y;
	if (keycode == ESC)
	{
		mlx_loop_end(all->game->mlx);
		free_struct_all(all);
		exit(0);
	}
	if (keycode == UP || keycode == W)
		post_y = all->game->player->y - 1;
	if (keycode == RIGHT || keycode == D)
		post_x = all->game->player->x + 1;
	if (keycode == LEFT || keycode == A)
		post_x = all->game->player->x - 1;
	if (keycode == DOWN || keycode == S)
		post_y = all->game->player->y + 1;
	move_player(all, post_x, post_y);
	return (0);
}

void	move_player(t_struct_all *all, int post_x, int post_y)
{
	int	cur_x;
	int	cur_y;
	t_collect *collect;
	int	exit_print_flg;

	exit_print_flg = 0;
	cur_x = all->game->player->x;
	cur_y = all->game->player->y;
	//  キー方向に移動できるかチェック（壁かどうか？）
	if (all->map->map_str[post_y][post_x] == WALL)
		return ;
	else if (all->map->map_str[post_y][post_x] == 'E')
	{
		// all get check
		if (all_get_check(all))
		{
			// ウィンドウほしい　見づらい
			mlx_string_put(all->game->mlx, all->game->win, 100, 100, 1, "get all collection!");
		}
		else
		{
			mlx_loop_end(all->game->mlx);
		}

		// TODO
		// 一度’E’を踏んだあとに隣の升に異動した場合、描画はどうなる？
	}
	else if (all->map->map_str[post_y][post_x] == 'C')
	{
		collect = *(all->game->c_list);
		while (collect)
		{
			if (collect->x == post_x && collect->y == post_y)
			{
				collect->get_flg = 1;
			}
			collect = collect->next;
		}
	}
	all->game->player->x = post_x;
	all->game->player->y = post_y;
	print_collect(all);
	print_player(all, cur_x, cur_y);
	all->game->count_move++;
	ft_printf("count_move %d\n", all->game->count_move);
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

int	all_get_check(t_struct_all *all)
{
	t_collect	*collect;

	collect = *(all->game->c_list);
	while (collect)
	{
		if (collect->get_flg == 0)
			return (1);
		collect = collect->next;
	}
	return (0);
}
