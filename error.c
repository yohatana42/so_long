/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:40:21 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/17 14:07:48 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(t_struct_all *all, char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	free_struct_all(all);
	exit(EXIT_FAILURE);
}
