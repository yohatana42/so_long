/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:40:21 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/13 19:04:19 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(t_map *map, char *str)
{
	write(2, "Error\n", 6);
	// perror(str);
	write(2, str, ft_strlen(str));
	map_free(map);
	exit(EXIT_FAILURE);
}

void	mlx_error(t_game *game, char *str)
{
	write(2, "Error\n", 6);
	perror(str);
	free(game);
	exit(EXIT_FAILURE);
}
