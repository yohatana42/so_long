/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:29:26 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/15 18:45:13 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_collect	**add_node(t_collect *c, t_collect **c_list)
{
	t_collect	*last;

	if (c_list == NULL && c == NULL)
		return (NULL);
	if (*c_list == NULL)
	{
		*c_list = c;
	}
	else
	{
		last = get_last(c_list);
		last->next = c;
	}
	return (c_list);
}

t_collect	*create_new(int x, int y)
{
	t_collect	*c;

	c = (t_collect *)ft_calloc(sizeof(t_collect), 1);
	if (!c)
		return (NULL);
	c->x = x;
	c->y = y;
	c->next = NULL;
	c->get_flg = OFF;
	return (c);
}

t_collect	*get_last(t_collect **c_list)
{
	t_collect	*c;

	c = *c_list;
	while (c->next)
	{
		c = c->next;
	}
	return (c);
}
