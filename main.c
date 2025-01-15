/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:23:38 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/15 18:47:31 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	main(int argc, char **argv)
{
	t_struct_all	*all;

	(void)argv;
	all = NULL;

	if (argc == 2)
	{
		printf("argc is 2\n");
		all = create_struct();
		if (validation_check(argv[1], all) == NG)
			error_exit(all, "arg check please");
		if (map_check(all) == NG)
			error_exit(all, "not playable map");
		game_init(all);
	}
	else
	{
		error_exit(all, "argc is 2");
	}
	free_struct_all(all);
	return (0);
}

/*
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
			error_exit(all, "malloc faled");
		if (validation_check(argv[1], all) == NG)
			error_exit(all, "arg check please");
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
	free_struct_all(all);
	return (EXIT_SUCCESS);
}
*/
