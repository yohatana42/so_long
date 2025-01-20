/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:36:45 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/20 16:59:17 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static int	validation_wall(t_map *map);
static int	count_char(t_struct_all *all, char c, int x, int y);
static int	validation_map_charactaer(t_struct_all *all);

int	validation_map(t_struct_all *all)
{
	all->map->width = (int)ft_strlen(all->map->map_str[0]);
	all->map->hight = get_map_hight(all->map);
	if (!validation_wall(all->map))
		return (0);
	validation_map_charactaer(all);
	return (1);
}

static int	validation_map_charactaer(t_struct_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->map->map_str[i] != NULL)
	{
		j = 0;
		while (j < all->map->width)
		{
			if (count_char(all, all->map->map_str[i][j], j, i) == 0)
				error_exit(all, "this is not map char");
			j++;
		}
		i++;
	}
	if (all->map->count_p != 1 || all->map->count_e != 1
		|| all->map->count_c < 1)
	{
		error_exit(all, "map is NOT perfect.'C' or 'P' or 'E' is NOT ");
		return (0);
	}
	map_route_search(all);
	return (1);
}

static int	validation_wall(t_map *map)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (i < map->hight)
	{
		line = map->map_str[i];
		if (i == 0 || i == map->hight -1)
		{
			j = 0;
			while (line[j] != '\0')
			{
				if (line[j] != WALL)
					return (0);
				j++;
			}
		}
		if (line[0] != WALL || line[ft_strlen(line) - 1] != WALL)
			return (0);
		i++;
	}
	return (1);
}

static int	count_char(t_struct_all *all, char c, int x, int y)
{
	t_collect	*new;

	if (c != 'P' && c != 'E' && c != 'C' && c != WALL && c != FLOOR)
		return (0);
	if (c == 'P')
	{
		all->map->count_p = all->map->count_p + 1;
		all->game->player->x = x;
		all->game->player->y = y;
	}
	if (c == 'E')
	{
		all->map->count_e = all->map->count_e + 1;
		all->game->exit->x = x;
		all->game->exit->y = y;
	}
	if (c == 'C')
	{
		all->map->count_c = all->map->count_c + 1;
		new = create_new(x, y);
		if (!new)
			error_exit(all, "malloc failed");
		all->game->c_list = add_node(new, all->game->c_list);
	}
	return (1);
}
