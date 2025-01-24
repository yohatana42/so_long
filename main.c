/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:23:38 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/23 22:33:34 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	main(int argc, char **argv)
{
	t_struct_all	*all;

	all = NULL;
	if (argc == 2)
	{
		all = create_struct();
		if (validation_argument(argv[1], all) == 0)
			error_exit(all, "argument check please");
		if (validation_map(all) == 0)
			error_exit(all, "this is not playable map");
		game_init(all);
	}
	else
		error_exit(all, "argc is 2");
	free_struct_all(all);
	return (0);
}
