/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:23:38 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/14 19:09:41 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	main(int argc, char **argv)
{
	t_struct_all	*all;

	all = (t_struct_all *)ft_calloc(sizeof(t_struct_all), 1);
	if (!all)
		error_exit(NULL, "malloc faled");
	if (argc == 2)
	{
		printf("argc = 2\n");
		all = create_struct(all);
		if (!all)
			error_exit(NULL, "malloc faled");
		if (validation_check(argv[1], all) == NG)
			return (EXIT_FAILURE);
		if (map_check(all) == NG)
			error_exit(all, "not playable map");

		// mlx hook
		game_init(all);


		// game_exec();
		// print
		// free_map(struct_all->map);
		free_struct_all(all);
	}
	else
	{
		perror("Error\n :argument is only 1");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
