/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:55:24 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/14 19:30:44 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static void	free_c_list(t_game *game);

t_game	*create_game_struct(t_game *game)
{
	t_player	*player;
	t_exit		*exit;
	t_collect	**c_list;
	t_game_img	*game_img;

	player = (t_player *)ft_calloc(sizeof(t_player), 2);
	if (!player)
		return (NULL);
	exit = (t_exit *)ft_calloc(sizeof(t_exit), 2);
	if (!exit)
		return (NULL);
	c_list = (t_collect **)ft_calloc(sizeof(t_collect *), 2);
	if (!c_list)
		return (NULL);
	game_img = (t_game_img *)ft_calloc(sizeof(t_game_img), 1);
	if (!game_img)
		return (NULL);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, "so_long");
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
		mlx_destroy_display(game->mlx);
		mlx_destroy_window(game->mlx, game->win);

		if (game->player)
			free(game->player);
		if (game->c_list)
			free_c_list(game);
		if (game->exit)
			free(game->exit);
		if (game->game_img)
			free(game->game_img);
		free(game);
	}
}

static void	free_c_list(t_game *game)
{
	t_collect	*collect;
	t_collect	*temp;

	collect = *(game->c_list);
	while (collect)
	{
		temp = collect;
		free(collect);
		collect = temp->next;
	}
	free(game->c_list);
}
