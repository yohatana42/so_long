/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_collect_get_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:31:07 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/17 20:31:45 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	all_get_check(t_struct_all *all)
{
	t_collect	*collect;

	collect = *(all->game->c_list);
	while (collect)
	{
		if (collect->get_flg == 0)
			return (1);
		collect = collect->next;
	}
	return (0);
}
