/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:58:41 by yohatana          #+#    #+#             */
/*   Updated: 2024/12/17 21:10:07 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"
# include "printf/libftprintf.h"
# include <math.h>

# include <X11/X.h>
# include <X11/keysym.h>

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# define SUCCESS 0
# define ERROR 1
# define OFF 0
# define ON 1
# define MAP_PATH "maps/\0"
# define BER_EXTE ".ber\0"
# define MAP_MAX_LIMIT 5000
# define WALL '1'
# define SPACE '0'

typedef struct s_count
{
	int		player;
	int		collection;
	int		exit;
}		t_count;

typedef struct s_collect
{
	int	x;
	int	y;
	int	get_flg;
}		t_collect;

typedef struct s_player
{
	int	x;
	int	y;
}		t_player;

typedef struct s_exit
{
	int	x;
	int	y;
}		t_exit;

typedef struct s_map
{
	int		player;
	int		collection;
	int		exit;
	char	**map_str;
	int		width;
	int		hight;
	t_count	*count;
}		t_map;

// main

// map_check
t_map	*map_check(char *map_name, t_map *map);
// char	*get_map_path(char *map_name);
// char	**map_read(int fd);
// int	map_name_check(char *map_name);
// int	map_charactaer_check(t_map *map);

// map_check_helper
int	map_charactaer_check(t_map *map);
int	get_map_hight(t_map *map);
// int	route_search(t_map *map, char object);
int	route_search(t_map *map, char object, int cur_x, int cur_y);

// aal_free
void	all_free(t_map *map);

#endif
