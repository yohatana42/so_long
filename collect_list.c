/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:29:26 by yohatana          #+#    #+#             */
/*   Updated: 2024/12/23 17:52:28 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_collect	**add_node(t_collect *c, t_collect **c_list)
{
	// t_collect	*top;
	t_collect	*last;

	printf("=====add_node=====\n");
	printf("c_list: %p\n", c_list);
	printf("c     : %p\n", c);
	printf("c     : %d\n", c->x);
	printf("c     : %d\n", c->y);
	printf("c     : %p\n", c->next);

	if (c_list == NULL && c == NULL)
		return (NULL);

	if (*c_list == NULL)
	{
		*c_list = c;
		printf("c_list: %p\n", c_list);
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
