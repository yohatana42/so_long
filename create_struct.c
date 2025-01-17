/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:07:06 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/17 14:32:33 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

t_struct_all	*create_struct(void)
{
	t_map			*map;
	t_game			*game;
	t_struct_all	*struct_all;

	struct_all = (t_struct_all *)ft_calloc(sizeof(t_struct_all), 1);
	if (!struct_all)
		error_exit(NULL, "malloc failed");
	map = (t_map *)ft_calloc(sizeof(t_map), 1);
	if (!map)
		(free(struct_all), error_exit(struct_all, "malloc failed\n"));
	map = create_map_struct(map);
	game = (t_game *)ft_calloc(sizeof(t_game), 1);
	if (!game)
		error_exit(struct_all, "malloc failed\n");
	game = create_game_struct(game);
	struct_all->map = map;
	struct_all->game = game;
	return (struct_all);
}

void	free_struct_all(t_struct_all *struct_all)
{
	if (!struct_all)
		return ;
	if (struct_all->map)
		free_map(struct_all->map);
	if (struct_all->game)
		free_game(struct_all->game);
	free(struct_all);
}
