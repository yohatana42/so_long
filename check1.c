/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somukaid <somukaid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:05:29 by somukaid          #+#    #+#             */
/*   Updated: 2024/12/19 03:56:56 by somukaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	argv_check(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Not good args!! It needs .ber\n", 2);
		return (1);
	}
	else
	{
		if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		{
			if (ft_strlen(argv[1]) == 4)
			{
				ft_putstr_fd("Error\n", 2);
				ft_putstr_fd("good file name?\n", 2);
				return (1);
			}
		}
		else
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd(".ber file?\n", 2);
			return (1);
		}
	}
	return (0);
}
