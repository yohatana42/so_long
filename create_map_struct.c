/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:40:41 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/13 19:08:03 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static void	free_c_list(t_map *map);

t_map	*create_map_struct(t_map *map)
{
	t_player	*player;
	t_exit		*exit;
	t_collect	**c_list;

	player = (t_player *)ft_calloc(sizeof(t_player), 2);
	if (!player)
		return (NULL);
	exit = (t_exit *)ft_calloc(sizeof(t_exit), 2);
	if (!exit)
		return (NULL);
	c_list = (t_collect **)ft_calloc(sizeof(t_collect *), 2);
	if (!c_list)
		return (NULL);
	map->count_p = 0;
	map->count_c = 0;
	map->count_e = 0;
	map->player = player;
	map->exit = exit;
	map->c_list = c_list;
	return (map);
}

void	map_free(t_map *map)
{
	int	i;

	i = 0;
	if (map)
	{
		if (map->map_str)
		{
			while (map->map_str[i])
				free(map->map_str[i++]);
			free(map->map_str);
		}
		i = 0;
		if (map->route_map)
		{
			while (map->route_map[i])
				free(map->route_map[i++]);
			free(map->route_map);
		}
		if (map->player)
			free(map->player);
		if (map->c_list)
			free_c_list(map);
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
