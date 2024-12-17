/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:50:38 by yohatana          #+#    #+#             */
/*   Updated: 2024/12/17 21:14:38 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

// static int	wall_check(char *line);
static int	wall_check(char *line, int hight_flg);
static int	add_char(t_map *map, char c);

int	map_charactaer_check(t_map *map)
{
	int		i;
	int		j;
	char	c;
	t_count	*count;

	i = 0;
	count = NULL;
	// 1行ずつ読み込む
	map->width = ft_strlen(map->map_str[0]);
	map->hight = get_map_hight(map);
	map->count = count;
	while (map->map_str[i] != NULL)
	{
		printf("i : %d str: %s\n", i, map->map_str[i]);
		if ((i == 0 || i == map->hight - 1) && !wall_check(map->map_str[i], OFF))
			return (0);
		 j = 0;
		while (j < map->width)
		{
			c = map->map_str[i][j];
			if (add_char(map, c))
				j++;
			else
			{
				printf("moji miss\n");
				return (0);
			}
		}
		i++;
	}
	if (map->player != 1 || map->exit != 1 || map->collection < 1)
		return (0);

	// PからCまでのルートを探索する
	int pass = 0;
	while (map->collection > c)
	{
		// route_search(map, 'C', 'P'の場所);
		// 'C'の構造体リスト
		pass++;
	}
	// route_search(map, 'E', 'P'の場所);
	// 幅優先探索か深さ優先探索でｐからEまでのルートを確保する

	return (1);
}

static int	wall_check(char *line, int hight_flg)
{
	size_t	i;

	i = 0;
	if (hight_flg == ON)
	{
		if (line[0] != WALL || line[ft_strlen(line) - 1] != WALL)
			return (0);
	}
	else
	{
		while (line[i] != '\0')
		{
			if (line[i] != WALL)
				return (0);
			i++;
		}
	}

	return (1);
}

static int	add_char(t_map *map, char c)
{
	if (c == 'P' || c == 'E' || c == 'C' || c == '1' || c == '0')
	{
		if (c == 'P')
			map->count->player = map->count->player + 1;
		if (c == 'E')
			map->count->exit = map->count->exit + 1;
		if (c == 'C')
			map->count->collection = map->count->collection + 1;
	}
	else
		return (0);
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

// 'P'->'C' or 'P'->'E'
// return 1 is OK, 0 is NO route
// int	route_search(t_map *map, char object)
// すべてのオブジェクトを通る
int	route_search(t_map *map, char object, int cur_x, int cur_y)
{
	int	result1;
	int	result2;
	int	result3;
	int	result4;

	// objectが複数ある場合はどうするべき？
	// 単純にここは一つのオブジェクトへの経路を確認する
	// スタート地点からどのくらい距離があるかで考える
	// 仮にスタートが5,5とする

	// 4, 5
	if (map->map_str[cur_x -1][cur_y] == WALL)
	{
		// ここは進めないので5, 4スタートでチェックを実行することはない
		return (0);
	}
	else
	{
		if (map->map_str[cur_x -1][cur_y] == object)
			return (1);
		else
			result1 = route_search(map, object, cur_x -1, cur_y);
	}
	if (map->map_str[cur_x +1][cur_y] == WALL)
		return (0);
	else
		result2 = route_search(map, object, cur_x +1, cur_y);
	if (map->map_str[cur_x][cur_y -1] == WALL)
		return (0);
	else
		result3 = route_search(map, object, cur_x, cur_y -1);
	if (map->map_str[cur_x][cur_y +1] == WALL)
		return (0);
	else
		result4 = route_search(map, object, cur_x, cur_y +1);
	if (result1 == 0 || result2 == 0 || result3 == 0 || result4 == 0)
		return (0);
	return (1);
}

