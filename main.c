/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:23:38 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/13 19:09:06 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	main(int argc, char **argv)
{
	t_map		*map;

	map = (t_map *)ft_calloc(sizeof(t_map), 2);
	if (!map)
		perror("malloc failed\n");
	if (argc == 2)
	{
		printf("argc = 2\n");
		map = create_map_struct(map);
		if (!map)
			map_error(map, "malloc failed");
		if (validation_check(argv[1], map) == NG)
			return (EXIT_FAILURE);
		if (map_check(argv[1], map) == NG)
			map_error(map, "not playable map");

		// mlx hook
		game_init(map);
		// print
		map_free(map);
	}
	else
	{
		perror("Error\n :argument is only 1");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
