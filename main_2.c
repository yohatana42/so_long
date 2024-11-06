/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:55:31 by yohatana          #+#    #+#             */
/*   Updated: 2024/09/16 13:33:09 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include <math.h>

#include <stdio.h>

// cc main.c minilibx-linux/libmlx_Linux.a minilibx-linux/libmlx.a -lm -lXext -lX11


typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_circle(int win_x, int win_y, t_data *img);
int	get_opposite(int color);

int	main(void)
{
	t_data	img;
	void	*mlx;
	void	*mlx_win;
	int		win_x;
	int		win_y;

	char	*relative_path = "./texture/onigiri_yakionigiri.png";

	win_x = 1920;
	win_y = 1080;

	// mlx init
	mlx = mlx_init();
	// create new window
	mlx_win = mlx_new_window(mlx, win_x, win_y, "Hello World!");

	// 一般的なピクセルを出す
	img.img = mlx_new_image(mlx, win_x, win_y);

/*
	// 焼きおにぎりを出す
	int img_width;
	int	img_height;
	// この関数どこにあるんだ　返り値はintだけどどこに格納すればいいんだ
	img.img = mlx_png_file_to_image(mlx, relative_path, &img_width, &img_height);
*/

	// image addres get!!!!!
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	// put pixel!!!!
	draw_circle(win_x, win_y, &img);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	// key conf
	mlx_loop(mlx);

	// ボタンがちゃがちゃやると反応するはず
	// mlx_hook(mlx_win, 9, 0, mlx_honyahonya_window(), 構造体の参照);

	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_circle(int win_x, int win_y, t_data *img)
{
	int	x;
	int	y;
	int	radius;
	int	temp;
	int	color;

	int	red;
	int	green;
	int	blue;

	// ビット演算で色を取得
	red = color >> 16;
	green = color >> 8 & 0xff;
	blue = color & 0xff;
	color = (red << 16) + (green << 8) + blue;

	x = 0;
	y = 0;
	temp = 0;
	radius = 100;
	color = 0x00FF0000;

	int	count;
	count = 0;

	while (y <= win_y)
	{
		while (x <= win_x)
		{
			temp = pow(x - 300, 2) + pow(y - 250, 2);
			// temp = (int)pow(x, 2) + (int)pow(y, 2);
			if (temp <= pow(radius, 2))
			{
				color = get_opposite(color);
				my_mlx_pixel_put(img, x, y, color);
				if (count == 100)
				{
					red = color >> 16;
					green = color >> 8 & 0xff;
					blue = color & 0xff;
					red = red - 1;
					color = (red << 16) + (green << 8) + blue;
					count = 0;
				}

				count++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

// kyori = 0 is nothing shade
// kyori = 1 is all darkness shade
// kyori = 0.5 is half dark shade
int	add_shade(double kyori, int color)
{
	return (0);
}

// return reflection color
int	get_opposite(int color)
{
	int red = color >> 16;
	int green = color >> 8 & 0xff;
	int blue = color & 0xff;

	int	min;
	int max;

	if (red < green)
	{
		max = green;
		min = red;
		if (green < blue)
		{
			max = blue;
		}
		else
		{
			if (blue < red)
				min = blue;
		}
	}
	else
	{
		max = red;
		min = green;
		if (red < blue)
		{
			max = blue;
		}
		else
		{
			if (blue < green)
				min = blue;
		}
	}

	red = (min + max) - red;
	green = (min + max) - green;
	blue = (min + max) - blue;
	color = (red << 16) + (green << 8) + blue;
	return (color);
}
