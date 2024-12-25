/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:05:29 by somukaid          #+#    #+#             */
/*   Updated: 2024/12/25 17:38:11 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	int		ret;

	ret = init(argc, argv, &data);
	if (ret != 0)
		return (1);
	in_path(&data);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map_x * 50, \
		data.map_y * 50, "so_long");
	data_image(&data);
	make_map(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, \
		data.img[4], data.player_x * 50, data.player_y * 50);
	mlx_loop_hook(data.mlx_ptr, is_goal, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, keyboad_push, &data);
	mlx_hook(data.win_ptr, 33, 1 << 17, press_cross, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	return (0);
}

int	init(int argc, char *argv[], t_data *data)
{
	int	ret;

	data->player = 0;
	data->collect = 0;
	data->end = 0;
	ret = argv_check(argc, argv);
	if (ret != 0)
		return (1);
	printf("argv_check:OK\n");
	ret = map_check(argv, data);
	if (ret != 0)
		return (1);
	printf("map_check:OK\n");
	return (0);
}

void	in_path(t_data *data)
{
	data->empty_path = "./img/my_empty.xpm";
	data->wall_path = "./img/my_wall.xpm";
	data->collect_path = "./img/my_collect.xpm";
	data->exit_path = "./img/my_exit.xpm";
	data->player_path = "./img/my_player.xpm";
}

void	data_image(t_data *data)
{
	data->img[0] = mlx_xpm_file_to_image(data->mlx_ptr, data->empty_path, \
		&(data->empty_width), &(data->empty_height));
	data->img[1] = mlx_xpm_file_to_image(data->mlx_ptr, data->wall_path, \
		&(data->wall_width), &(data->wall_height));
	data->img[2] = mlx_xpm_file_to_image(data->mlx_ptr, data->collect_path, \
		&(data->collect_width), &(data->collect_height));
	data->img[3] = mlx_xpm_file_to_image(data->mlx_ptr, data->exit_path, \
		&(data->exit_width), &(data->exit_height));
	data->img[4] = mlx_xpm_file_to_image(data->mlx_ptr, data->player_path, \
		&(data->player_width), &(data->player_height));
}

int	press_cross(int key, t_data *data)
{
	(void)key;
	(void)data;
	exit (0);
}
