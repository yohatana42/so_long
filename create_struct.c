/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:40:41 by yohatana          #+#    #+#             */
/*   Updated: 2024/12/21 16:27:24 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static void	free_c_list(t_map *map);

t_map	*create_struct(t_map *map)
{
	printf("create_struct\n");
	t_count		*count;
	t_player	*player;
	t_exit		*exit;

	count = (t_count *)malloc(sizeof(t_count) * 1);
	if (!count)
		return (NULL);
	player = (t_player *)malloc(sizeof(t_player) * 1);
	if (!player)
		return (NULL);
	exit = (t_exit *)malloc(sizeof(exit) * 1);
	if (!exit)
		return (NULL);
	map->count = count;
	map->player = player;
	map->exit = exit;
	map->c_list = NULL;
	return (map);
}

void	all_free(t_map *map)
{
	if (map)
	{
		if (map->map_str)
			free(map->map_str);
		if (map->player)
			free(map->player);
		if (map->c_list)
			free_c_list(map);
		if (map->count)
			free(map->count);
		if (map->exit)
			free(map->exit);
		free(map);
	}
	exit(EXIT_FAILURE);
}

static void	free_c_list(t_map *map)
{
	t_collect	*collect;
	t_collect	*temp;

	collect = *(map->c_list);
	while (collect)
	{
		temp = collect;
		free(collect);
		collect = temp->next;
	}
	free(map->c_list);
}
