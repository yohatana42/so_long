/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:58:41 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/13 19:09:48 by yohatana         ###   ########.fr       */
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
# include <stdlib.h>

# define ERROR -1
# define OFF 0
# define ON 1
# define NG 0
# define OK 1
# define MAP_PATH "maps/\0"
# define BER_EXTE ".ber\0"
# define MAP_MAX_LIMIT 5000
# define WALL '1'
# define SPACE '0'
# define IMG_H 30
# define IMG_W 30
# define WIN_H 500
# define WIN_W 1000

typedef struct s_collect	t_collect;

typedef struct s_place
{
	int		x;
	int		y;
}		t_place;

typedef struct s_player
{
	int		x;
	int		y;
}		t_player;

typedef struct s_exit
{
	int		x;
	int		y;
}		t_exit;

typedef struct s_collect
{
	int			x;
	int			y;
	int			get_flg;
	t_collect	*next;
}		t_collect;

typedef struct s_struct_all
{
	int			x;
	int			y;
	int			get_flg;
	t_collect	*next;
}		t_struct_all;


typedef struct s_map
{
	t_player	*player;
	t_collect	**c_list;
	t_exit		*exit;
	char		**map_str;
	int			width;
	int			hight;
	int			**route_map;
	// t_count		*count;
	int			count_p;
	int			count_c;
	int			count_e;
}		t_map;

typedef	struct	s_game_img
{
	void	*player;
	void	*collect;
	void	*exit;
	void	*wall;
	void	*floor;
}	t_game_img;

typedef	struct	s_game
{
	void		*mlx;
	void		*win;
	t_game_img *game_img;
}	t_game;



// main

// validation_check.c
int			validation_check(char *map_name, t_map *map);

// map_check
int			map_check(char *map_name, t_map *map);
int			map_charactaer_check(t_map *map);

// map_check_helper
int			get_map_hight(t_map *map);

// map_rote_search
int			map_route_search(t_map *map);
int			route_search_c(t_map *map, t_collect *object, int cur_x, int cur_y);
int			search_c_helper(t_map *map, t_collect *object, int cur_x, int cur_y);
int			route_search_e(t_map *map, t_exit *object, int cur_x, int cur_y);
int			search_e_helper(t_map *map, t_exit *object, int cur_x, int cur_y);

// c_list
t_collect	**add_node(t_collect *c, t_collect **c_list);
t_collect	*create_new(int x, int y);
t_collect	*get_last(t_collect **c_list);

// create_sturucture
t_map		*create_map_struct(t_map *map);
void		map_free(t_map *map);

// game_init
int			game_init(t_map *map);

// error
void		map_error(t_map *map, char *str);

// game_init
int			game_init(t_map *map);

// create_mlx_struct
t_game		*create_game_struct(void);

#endif
