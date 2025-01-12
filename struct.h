/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:51:06 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/12 13:58:46 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "so_long.h"
# include "game.h"

typedef struct s_collect	t_collect;

typedef struct s_count
{
	int		p;
	int		c;
	int		e;
}		t_count;

typedef struct s_player
{
	int		x;
	int		y;
	void	*img;
	char	*path;
	int		img_w;
	int		img_h;
}		t_player;

typedef struct s_exit
{
	int		x;
	int		y;
	void	*img;
	char	*path;
	int		img_w;
	int		img_h;
}		t_exit;

typedef struct s_collect
{
	int			x;
	int			y;
	int			get_flg;
	int			check_flg;
	void		*img;
	char		*path;
	t_collect	*next;
}		t_collect;

typedef struct s_map
{
	t_player	*player;
	t_collect	**c_list;
	t_exit		*exit;
	char		**map_str;
	int			width;
	int			hight;
	int			**route_map;
	t_count		*count;
}		t_map;

typedef	struct	s_wall
{
	void	*img;
	char	*path;
	int		img_w;
	int		img_h;
}	t_wall;

typedef	struct	s_space
{
	void	*img;
	char	*path;
	int		img_w;
	int		img_h;
}	t_space;

typedef	struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;
	t_wall	*wall;
	t_space	*space;
}	t_mlx;

#endif
