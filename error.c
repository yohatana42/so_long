/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:40:21 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/11 15:13:02 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "game.h"

void	map_error(t_map *map, char *str)
{
	write(2, "Error\n", 6);
	// perror(str);
	write(2, str, ft_strlen(str));
	map_free(map);
	exit(EXIT_FAILURE);
}

void	mlx_error(t_mlx *mlx_data, char *str)
{
	write(2, "Error\n", 6);
	perror(str);
	free(mlx_data);
	exit(EXIT_FAILURE);
}
