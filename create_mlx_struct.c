/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mlx_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:55:24 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/12 18:32:12 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

t_mlx	*create_mlx_struct(void)
{
	t_mlx	*mlx;
	t_wall	*wall;
	t_space	*space;

	mlx = (t_mlx *)ft_calloc(sizeof(mlx), 1);
	if (!mlx)
		return (NULL);
	wall = (t_wall *)ft_calloc(sizeof(t_wall), 1);
	if (!wall)
		return (NULL);
	space = (t_space *)ft_calloc(sizeof(t_space), 1);
	if (!space)
		return (NULL);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1920, 1080, "so_long");
	mlx->wall = wall;
	mlx->space = space;
	return (mlx);
}
