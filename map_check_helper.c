/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:50:38 by yohatana          #+#    #+#             */
/*   Updated: 2024/12/15 19:20:19 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

static int	wall_check(char *line);
static int	add_char(t_map *map, char c);

int	map_charactaer_check(t_map *map)
{
	int		i;
	int		j;
	char	c;

	j = 0;
	i = 0;
	// 1行ずつ読み込む
	map->width = ft_strlen(map->map_str[0]);
	map->hight = get_map_hight(map);
	while (map->map_str[i] != NULL)
	{
		printf("i : %d str: %s\n", i, map->map_str[i]);
		// 1行目は壁
		if ((i == 0 || i == map->hight - 1) && !wall_check(map->map_str[i]))
			return (0);
		// 必要な文字の種類があれば構造体に記載
		while (j < map->width)
		{
			c = map->map_str[i][j];
			if (add_char(map, c))
				j++;
			else
				return (0);
		}
		j = 0;
		i++;
	}

	// PからCまでのルートを探索する
	// 幅優先探索か深さ優先探索でｐからEまでのルートを確保する

	// 最後まで読んで必要な文字が足りないか確認
	return (1);
}

static int	wall_check(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != WALL)
			return (0);
		i++;
	}
	return (1);
}

static int	add_char(t_map *map, char c)
{
	if (c == 'P' || c == 'E' || c == 'C' || c == '1' || c == '0')
	{
		printf("mojiha atteru\n");
		if (c == 'P')
			map->player = map->player + 1;
		if (c == 'E')
			map->exit = map->exit + 1;
		if (c == 'C')
			map->corection = map->corection + 1;
	}
	else
		return (0);
	if (map->player > 1 || map->exit > 1)
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
