/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:40:41 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/14 20:28:25 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

t_map	*create_map_struct(t_map *map)
{
	map->hight = 0;
	map->width = 0;
	map->map_str = NULL;
	map->route_map = NULL;
	map->count_p = 0;
	map->count_c = 0;
	map->count_e = 0;
	return (map);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
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
	free(map);
	// exit(EXIT_FAILURE);
}
