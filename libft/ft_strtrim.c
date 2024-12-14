/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:23:53 by yohatana          #+#    #+#             */
/*   Updated: 2024/05/19 13:13:33 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	set_search(char s1_char, char const *set);
static char	*get_start(char const *s1, char const *set);
static char	*get_end(char *start, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	char	*start;
	char	*end;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	start = get_start(s1, set);
	end = get_end(start, set);
	result = ft_substr(start, 0, end - start + 1);
	return (result);
}

// retun (1) is find
static int	set_search(char s1_char, char const *set)
{
	while (*set != '\0')
	{
		if (s1_char == *set)
			return (1);
		set++;
	}
	return (0);
}

static	char	*get_start(char const *s1, char const *set)
{
	char	*start;
	int		find_flg;

	start = (char *)s1;
	find_flg = 0;
	while (*start != '\0')
	{
		if (set_search(*start, set) == 0)
			return (start);
		start++;
	}
	return (start);
}

static char	*get_end(char *start, char const *set)
{
	char	*end;

	end = start + ft_strlen(start) - 1;
	while (end > start)
	{
		if (set_search(*end, set) == 0)
			return (end);
		end--;
	}
	return (end);
}
