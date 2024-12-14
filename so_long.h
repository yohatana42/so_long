/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:58:41 by yohatana          #+#    #+#             */
/*   Updated: 2024/12/14 21:30:55 by yohatana         ###   ########.fr       */
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
# define ERROR -1
# define MAP_PATH "maps/\0"
# define BER_EXTE ".ber\0"
# define MAP_MAX 5000

typedef struct s_map
{
	int		player;
	int		corection;
	int		exit;
	char	**map_str;
	int		width;
	int		hight;
}		t_map;

// main

// map_check
t_map	*map_check(char *map_name, t_map *map);
// char	*get_map_path(char *map_name);
// char	**map_read(int fd);
// int	map_name_check(char *map_name);
// int	map_charactaer_check(t_map *map);

#endif
