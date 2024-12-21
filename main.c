/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:23:38 by yohatana          #+#    #+#             */
/*   Updated: 2024/12/21 16:31:17 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	main(int argc, char **argv)
{
	t_map		*map;
	// t_count		*count;
	// t_player	*player;
	// t_collect	**c_list;
	// 	t_count		*count;
	// t_player	*player;
	// t_exit		*exit;
	// t_collect	**c_list;

	// c_list = NULL;
		// t_player	*player;
	// t_exit		*exit;
	// t_collect	**c_list;
	// count = (t_count *)malloc(sizeof(t_count) * 1);
	// player = (t_player *)malloc(sizeof(t_player) *1);
	// exit = (t_exit *)malloc(sizeof(exit) * 1);
	map = (t_map *)malloc(sizeof(t_map) * 1);
	if (!map)
		perror("malloc failed\n");
	if (argc == 2)
	{
		printf("argc = 2\n");
		map = create_struct(map);
		if (!map)
		{
			perror("malloc failed");
			all_free(map);
		}
		if (map_check(argv[1], map) == NG)
			return (EXIT_FAILURE);
		// mlx hook
		// print
		all_free(map);
	}
	else
	{
		perror("Error\n :argument is only 1");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
