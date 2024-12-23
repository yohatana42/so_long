/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:23:38 by yohatana          #+#    #+#             */
/*   Updated: 2024/12/23 22:04:21 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	main(int argc, char **argv)
{
	t_map		*map;

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
