/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:50:38 by yohatana          #+#    #+#             */
/*   Updated: 2024/12/21 16:19:49 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static int	wall_check(char *line);
// static int	wall_check(t_map *map,char *line, int hight_flg);
static int	wall_check(t_map *map);
static int	count_char(t_map *map, char c, int x, int y);
// int	route_search(t_map *map, char object, int cur_x, int cur_y);

int	map_charactaer_check(t_map *map)
{
	// t_count		*count;
	// t_player	*player;
	// t_exit		*exit;

	int i = 0;
	int j = 0;

	map->width = (int)ft_strlen(map->map_str[0]);
	map->hight = get_map_hight(map);
	// count = (t_count *)malloc(sizeof(t_count) * 1);
	// if (!count)
	// 	return (0);
	// player = (t_player *)malloc(sizeof(t_player) *1);
	// if (!player)
	// 	return (0);
	// exit = (t_exit *)malloc(sizeof(exit) * 1);
	// if (!exit)
	// 	return (0);
	// map->count = count;
	// map->player = player;
	// map->exit = exit;
	if (!wall_check(map))
		return (0);

	while (map->map_str[i] != NULL)
	{
		j = 0;
		while (j < map->width)
		{
			// if (!count_char(map))
			if (!count_char(map, map->map_str[i][j], j, i))
			{
				perror("Error\n : this is not char");
				return (0);
			}
			j++;
		}
		i++;
	}
	if (map->count->p != 1 || map->count->e != 1 || map->count->c < 1)
		return (0);

	printf("P :%d C :%d E :%d\n", map->count->p, map->count->c, map->count->e);

	// PからCまでのルートを探索する
	// printf("c_list: %p object :%p\n", map->c_list, *(map->c_list));
	// int result = 0;
	// t_collect	*object;
	// object = *(map->c_list);
	// while (object)
	// {
	// 	// result = route_search(map, 'C', map->player->x, map->player->y);
	// 	result = route_search_c(map, object, map->player->x, map->player->y);
	// 	if (result == 0)
	// 		perror("Error\n : No route to 'C', check map");
	// 	object->check_flg = ON;
	// 	object = object->next;
	// }

	// route_search(map, 'E', 'P'の場所);
	// result = route_search(map, 'E', map->player->x, map->player->y);
	// if (result == 0)
	// 	perror("Error\n : No route to 'E', check map");

	return (1);
}

static int	wall_check(t_map *map)
{
	// size_t	i;
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (i < map->hight)
	{
		line = map->map_str[i];
		printf("i : %d str: %s\n", i, map->map_str[i]);
		printf("map->hight :%d map->width: %d\n", map->hight, map->width);
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

// static int	count_char(t_map *map)
static int	count_char(t_map *map, char c, int x, int y)
{
	// int y = 0;
	// int x = 0;
	// char c;

	// while (y < map->hight)
	// {
	// 	while (x < map->width)
	// 	{
	// 		c = map->map_str[y][x];
			if (c != 'P' && c != 'E' && c != 'C' && c != WALL && c != SPACE)
				return (0);
			if (c == 'P')
			{
				map->count->p = map->count->p + 1;
				map->player->x = x;
				map->player->y = y;
			}
			if (c == 'E')
			{
				map->count->e = map->count->e + 1;
				map->exit->x = x;
				map->exit->y = y;
			}
			if (c == 'C')
			{
				map->count->c = map->count->c + 1;
				add_node(create_new(x, y), map->c_list);
			}
	// 		x++;
	// 	}
	// 	y++;
	// }
	if (map->count->p > 1)
		perror("Error\n : map is NOT perfect.'P' more than 1");
	if (map->count->e > 1)
		perror("Error\n : map is NOT perfect.'E' more than 1");
	return (1);
}


int	get_map_hight(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_str[i] != NULL)
		i++;
	return (i);
}

/*
// 'P'->'C' or 'P'->'E'
// return 1 is OK, 0 is NO route
// すべてのオブジェクトを通る
int	route_search(t_map *map, char object, int cur_x, int cur_y)
{
	int	result1 = 0;
	int	result2 = 0;
	int	result3 = 0;
	int	result4 = 0;

	// int	obj_x;
	// int	obj_y;

	// 型がわからないと変換できない
	// obj_x = object->x;
	// obj_y = object->y;

	// int	up_flg;
	// int	down_flg;
	// int	left_flg;
	// int	right_flg;

	// up_flg = ON;
	// down_flg = ON;
	// left_flg = ON;
	// right_flg = ON;

	(void)map;

// どうして１万回も呼び出されているんですか？
	printf("route_search\n");
	printf("x: %d y: %d\n", cur_x, cur_y);

	if (cur_x < 0 || map->width < cur_x || cur_y < 0 || map->hight < cur_y)
		return (0);

	if (map->map_str[cur_x -1][cur_y] == WALL)
		result1 = 0;
	else if (map->map_str[cur_x -1][cur_y] == object)
		return (1);
	else
		result1 = route_search(map, object, cur_x -1, cur_y);

	// printf("left_flg %d\n", left_flg);

	if (map->map_str[cur_x +1][cur_y] == WALL)
		result2 = 0;
	else if (map->map_str[cur_x +1][cur_y] == object)
		return (1);
	else
		result2 = route_search(map, object, cur_x +1, cur_y);
	if (map->map_str[cur_x][cur_y -1] == WALL)
		result3 = 0;
	else if (map->map_str[cur_x][cur_y -1] == object)
		return (1);
	else
		result3 = route_search(map, object, cur_x, cur_y -1);
	if (map->map_str[cur_x][cur_y +1] == WALL)
		result4 = 0;
	else if (map->map_str[cur_x][cur_y +1] == object)
		return (1);
	else
		result4 = route_search(map, object, cur_x, cur_y +1);
	if (result1 == 0 && result2 == 0 && result3 == 0 && result4 == 0)
		return (0);
	return (1);
}
*/

// int	route_search_c(t_map *map, t_collect *object, int cur_x, int cur_y)
// {
// 	int	result1;
// 	int	result2;
// 	int	result3;
// 	int	result4;

// 	printf("x: %d y: %d\n", cur_x, cur_y);

// 	if (cur_x < 0 || map->width < cur_x || cur_y < 0 || map->hight < cur_y)
// 		return (0);
// 	if (map->map_str[cur_x -1][cur_y] == WALL)
// 		result1 = 0;
// 	else if (cur_x -1 == object->x && cur_y == object->y)
// 		return (1);
// 	else
// 		result1 = route_search_c(map, object, cur_x -1, cur_y);
// 	if (map->map_str[cur_x +1][cur_y] == WALL)
// 		result2 = 0;
// 	else if (cur_x +1 == object->x && cur_y == object->y)
// 		return (1);
// 	else
// 		result2 = route_search_c(map, object, cur_x +1, cur_y);
// 	if (map->map_str[cur_x][cur_y -1] == WALL)
// 		result3 = 0;
// 	else if (cur_x == object->x && cur_y -1 == object->y)
// 		return (1);
// 	else
// 		result3 = route_search_c(map, object, cur_x, cur_y -1);
// 	if (map->map_str[cur_x][cur_y +1] == WALL)
// 		result4 = 0;
// 	else if (cur_x == object->x && cur_y +1 == object->y)
// 		return (1);
// 	else
// 		result4 = route_search_c(map, object, cur_x, cur_y +1);
// 	if (result1 == 0 && result2 == 0 && result3 == 0 && result4 == 0)
// 		return (0);
// 	return (1);
// }
