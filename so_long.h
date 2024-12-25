/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somukaid <somukaid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:05:29 by somukaid          #+#    #+#             */
/*   Updated: 2024/12/19 04:16:09 by somukaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "get_next_line.h"

# define ESC_KEY 65307
# define LEFT_KEY 65361
# define UP_KEY 65362
# define RIGHT_KEY 65363
# define DOWN_KEY 65364
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img[5];
	size_t	player;
	size_t	collect;
	size_t	end;
	int		**map;
	int		player_x;
	int		player_y;
	int		map_x;
	int		map_y;
	char	*player_path;
	int		player_width;
	int		player_height;
	char	*wall_path;
	int		wall_width;
	int		wall_height;
	char	*collect_path;
	int		collect_width;
	int		collect_height;
	char	*exit_path;
	int		exit_width;
	int		exit_height;
	char	*empty_path;
	int		empty_width;
	int		empty_height;
	int		cross;
}	t_data;

typedef struct s_mapc
{
	int		fd;
	int		count;
	char	*line;
	size_t	len;
}	t_mapc;

// main.c
int		init(int argc, char *argv[], t_data *data);
void	in_path(t_data *data);
void	data_image(t_data *data);
int		press_cross(int key, t_data *data);

// check1.c
int		argv_check(int argc, char *argv[]);

// check2.c
int		map_check(char *argv[], t_data *data);
void	move(int x, int y, t_data *data);
void	move_r(int x, int y, t_data *data);
void	is_wall(t_data *data);
void	is_3piece(t_data *data);

// map_check1.c
int		is_openmap(char *argv, t_mapc *mapc);
int		is_mapxsize(t_data *data, t_mapc *mapc);
int		is_squarecheck(t_mapc *mapc);
int		is_mapysize(t_data *data, t_mapc *mapc);
void	alpha_to_mapint(t_data *data, t_mapc *mapc, int *i, int *j);

// map_check2.c
int		map_alloc(t_data *data, t_mapc *mapc, int *i, char *argv);
void	load_map(t_data *data, t_mapc *mapc, int *i, int *j);
int		can_playing(t_data *data, int *i, int *j);

// game1.c
void	make_map(t_data *data);
int		print_stage(t_data *data);
int		keyboad_push(int key, t_data *data);
int		is_goal(t_data *data);
void	frees(t_data *data);

// game2.c
void	esckey_push(t_data *data);
void	leftkey_push(t_data *data, size_t *move);
void	rightkey_push(t_data *data, size_t *move);
void	upkey_push(t_data *data, size_t *move);
void	downkey_push(t_data *data, size_t *move);

#endif
