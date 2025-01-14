/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:36:45 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/14 19:11:39 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static int	wall_check(t_map *map);
static int	count_char(t_struct_all *all, char c, int x, int y);
static int	map_charactaer_check(t_struct_all *all);

// int	map_check(char *map_name, t_map *map)
int	map_check(t_struct_all *all)
{
	all->map->width = (int)ft_strlen(all->map->map_str[0]);
	all->map->hight = get_map_hight(all->map);
	if (!wall_check(all->map))
		return (0);
	if (map_charactaer_check(all) == OK)
	{
		printf("ok\n");
		// game start
	}
	return (1);
}

static int	map_charactaer_check(t_struct_all *all)
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
				error_exit(all, "Error\n : this is not map char");
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

static int	wall_check(t_map *map)
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
	i = 0;
	return (1);
}

static int	count_char(t_struct_all *all, char c, int x, int y)
{
	(void)x;
	(void)y;
	if (c != 'P' && c != 'E' && c != 'C' && c != WALL && c != SPACE)
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
		all->game->c_list = add_node(create_new(x, y), all->game->c_list);
	}
	return (1);
}

