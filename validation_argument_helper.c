/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_check_helper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:05:53 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/17 20:13:36 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static int	count_return(char *str);

int	get_count_line(char *path, t_struct_all *all)
{
	int		count_line;
	int		fd;
	char	str[BUF_SIZE];
	int		result;

	count_line = 1;
	ft_bzero(str, BUF_SIZE);
	fd = open(path, O_RDONLY);
	while (1)
	{
		result = read(fd, str, BUF_SIZE);
		if (result < 0)
		{
			free(path);
			error_exit(all, "open file faild");
		}
		else if (result == 0)
			break ;
		count_line = count_line + count_return(str);
	}
	close(fd);
	return (count_line);
}

static int	count_return(char *str)
{
	int	i;
	int	count_line;

	i = 0;
	count_line = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] != '\0')
			count_line++;
		i++;
	}
	return (count_line);
}
