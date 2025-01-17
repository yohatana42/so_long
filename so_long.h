/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:58:41 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/17 20:32:15 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"
# include "printf/libftprintf.h"
# include "get_next_line/get_next_line.h"
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
# define WALL '1'
# define FLOOR '0'
# define IMG_H 50
# define IMG_W 50
# define BUF_SIZE 1000

# define ESC 65307
# define UP 65362
# define LEFT 65361
# define RIGHT 65363
# define DOWN 65364
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_collect	t_collect;

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

typedef struct s_map
{
	char		**map_str;
	int			width;
	int			hight;
	int			**route_map;
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
	int			count_move;
	t_game_img	*game_img;
	t_player	*player;
	t_collect	**c_list;
	t_exit		*exit;
}	t_game;

typedef struct s_struct_all
{
	t_map		*map;
	t_game		*game;
}		t_struct_all;

// main

// validation_check.c
int				validation_check(char *map_name, t_struct_all *all);

// validation_check_helper.c
int				get_count_line(char *path, t_struct_all *all);

// map_check
int				map_check(t_struct_all *struct_all);

// map_check_helper
int				get_map_hight(t_map *map);

// map_rote_search
int				map_route_search(t_struct_all *all);
void			route_map_init(t_map *map);

int				route_search_e(t_map *map, t_exit *object, int cur_x, int cur_y);
int				search_e_helper(t_map *map, t_exit *object, int cur_x, int cur_y);

// search.c
void			search_c(t_struct_all *all);
int				route_search_c(t_map *map, t_collect *object, int cur_x, int cur_y);
int				search_c_helper(t_map *map, t_collect *object, int cur_x, int cur_y);

// c_list
t_collect		**add_node(t_collect *c, t_collect **c_list);
t_collect		*create_new(int x, int y);
t_collect		*get_last(t_collect **c_list);


// error
void			error_exit(t_struct_all *all, char *str);

// game_init
int				game_init(t_struct_all *all);
int				print_collect(t_struct_all *all);

// game_event
int				on_destroy(t_struct_all *all);
int				key_hook(int keycode, t_struct_all *all);
void			move_player(t_struct_all *all, int post_x, int post_y);
void			print_player(t_struct_all *all, int cur_x, int cur_y);

// all collect get check
int	all_get_check(t_struct_all *all);

// create_struct
t_struct_all	*create_struct(void);
void			free_struct_all(t_struct_all *struct_all);

// create_game_struct
t_game			*create_game_struct(t_game *game);
void			free_game(t_game *game);

// create_sturucture
t_map			*create_map_struct(t_map *map);
void			free_map(t_map *map);

// game_print
void			print_img(t_struct_all *all);
int				print_collect(t_struct_all *all);

#endif
