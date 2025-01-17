/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:55:24 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/17 15:09:41 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static void	free_c_list(t_game *game);
static void	free_game_img(t_game *game);

t_game	*create_game_struct(t_game *game)
{
	t_player	*player;
	t_exit		*exit;
	t_collect	**c_list;
	t_game_img	*game_img;

	player = (t_player *)ft_calloc(sizeof(t_player), 1);
	if (!player)
		return (NULL);
	exit = (t_exit *)ft_calloc(sizeof(t_exit), 1);
	if (!exit)
		return (NULL);
	c_list = (t_collect **)ft_calloc(sizeof(t_collect *), 1);
	if (!c_list)
		return (NULL);
	game_img = (t_game_img *)ft_calloc(sizeof(t_game_img), 1);
	if (!game_img)
		return (NULL);
	game->mlx = NULL;
	game->win = NULL;
	game->count_move = 0;
	game->player = player;
	game->exit = exit;
	game->c_list = c_list;
	game->game_img = game_img;
	return (game);
}

void	free_game(t_game *game)
{
	if (game)
	{
		if (game->game_img)
			free_game_img(game);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
			mlx_destroy_display(game->mlx);
		free(game->player);
		free_c_list(game);
		free(game->exit);
		free(game->mlx);
		free(game);
	}
}

static void	free_game_img(t_game *game)
{
	if (game->game_img->wall)
	{
		mlx_destroy_image(game->mlx, game->game_img->wall);
	}
	if (game->game_img->floor)
	{
		mlx_destroy_image(game->mlx, game->game_img->floor);
	}
	if (game->game_img->exit)
	{
		mlx_destroy_image(game->mlx, game->game_img->exit);
	}
	if (game->game_img->player)
	{
		mlx_destroy_image(game->mlx, game->game_img->player);
	}
	if (game->game_img->collect)
	{
		mlx_destroy_image(game->mlx, game->game_img->collect);
	}
	free(game->game_img);
}

static void	free_c_list(t_game *game)
{
	t_collect	*collect;
	t_collect	*temp;

	if (!game->c_list)
		return ;
	if (*(game->c_list))
	{
		collect = *(game->c_list);
		while (collect)
		{
			temp = collect->next;
			free(collect);
			collect = temp;
		}
	}
	free(game->c_list);
}
