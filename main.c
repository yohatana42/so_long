/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:23:38 by yohatana          #+#    #+#             */
/*   Updated: 2024/12/14 20:44:15 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map) * 1);
	if (!map)
		perror("malloc failed\n");
	if (argc == 2)
	{
		// argv[1] が.berファイルかチェックするべき
		printf("argc = 2\n");
		map = map_check(argv[1], map);
		// map check
		// mlx hook
		// print

	}
	else
	{
		perror("argument is only 1");
	}
	return (SUCCESS);
}
