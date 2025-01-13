/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mlx_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:55:24 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/13 19:03:18 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

t_game	*create_game_struct(void)
{
	t_game	*game;

	game = (t_game *)ft_calloc(sizeof(t_game), 1);
	if (!game)
		return (NULL);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, "so_long");
	return (game);
}

void	free_mlx(t_game *game)
{
	if (game)
		free(game);
}
