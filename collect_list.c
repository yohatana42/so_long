/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:29:26 by yohatana          #+#    #+#             */
/*   Updated: 2024/12/21 16:59:44 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_collect	**add_node(t_collect *c, t_collect **c_list)
{
	t_collect	**top;
	t_collect	*last;

	printf("=====add_node=====\n");
	top = c_list;
	if (c_list == NULL && c == NULL)
		return (NULL);
	if (c_list == NULL)
	{
		c_list = &c;
		top = c_list;
		// printf("c_list: %p\n", c_list);
	}
	else
	{
		last = get_last(c_list);
		last->next = c;
	}
	// printf("c_list: %p\n", c_list);
	// printf("c     : %p\n", c);
	return (top);
}

t_collect	*create_new(int x, int y)
{
	t_collect	*c;

	c = (t_collect *)malloc(sizeof(t_collect) * 1);
	c->x = x;
	c->y = y;
	c->next = NULL;
	c->get_flg = OFF;
	c->check_flg = OFF;
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
