/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:18:06 by yohatana          #+#    #+#             */
/*   Updated: 2024/06/01 18:44:32 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"

static void	read_str(const char *str, va_list ap, int *result_count);
static void	check_specifier(const char *str, va_list ap, int *result_count);

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		result_count;

	result_count = 0;
	va_start(ap, str);
	read_str(str, ap, &result_count);
	va_end(ap);
	return (result_count);
}

static void	read_str(const char *str, va_list ap, int *result_count)
{
	int	space_flag;

	space_flag = 0;
	while (*str)
	{
		if (*str == '%' || space_flag)
		{
			str++;
			if (*str == ' ')
			{
				if (space_flag == 0)
					ft_putchar(' ', result_count);
				space_flag = 1;
			}
			check_specifier(str, ap, result_count);
		}
		else
		{
			ft_putchar(*str, result_count);
			space_flag = 0;
		}
		str++;
	}
}

static void	check_specifier(const char *str, va_list ap, int *result_count)
{
	if (*str == 'c')
		ft_putchar(va_arg(ap, int), result_count);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(ap, int), result_count);
	else if (*str == 's')
		ft_putstr(va_arg(ap, char *), result_count);
	else if (*str == 'p')
		ft_putpoint(va_arg(ap, unsigned long long), result_count);
	else if (*str == 'u')
		ft_putunbr(va_arg(ap, int), result_count);
	else if (*str == 'x' || *str == 'X')
		ft_puthex(va_arg(ap, unsigned long long), result_count, *str);
	else if (*str == '%')
		ft_putchar('%', result_count);
}
/*
#include <assert.h>
#include <limits.h>
#include<stdio.h>
int	main(void)
{
	// ft_printf("test1 %%c start\n");
	// int result1 = ft_printf("|%c|", 't');
	// printf("\n");
	// printf("test1 %d\n",result1);
	// printf("%d", printf("|%c|", 't'));
	// printf("\n");

	// int result1_2 = ft_printf("|%c|", '\n');
	// printf("\n");
	// printf("test1_2 %d\n",result1_2);
	// printf("%d", printf("|%c|", '\n'));
	// printf("\n");

	// ft_printf("test2 :%%d start\n");
	// int result2 = ft_printf("|%d|", -42);
	// printf("\n");
	// printf("test2 %d\n",result2);
	// printf("%d\n", printf("|%d|", -42));
	// printf("\n");

	// int result2_2 = ft_printf("|%d|", INT_MIN);
	// printf("\n");
	// printf("test2_2 %d\n",result2_2);
	// printf("%d\n", printf("|%d|", INT_MIN));
	// printf("\n");

	// int result2_3 = ft_printf("|%d|", 2147483647);
	// printf("\n");
	// printf("test2_3 %d\n",result2_3);
	// printf("%d\n", printf("|%d|", 2147483647));
	// printf("\n");

	// ft_printf("test3 :%%i start\n");
	// int result3 = ft_printf("|%i|", 42);
	// printf("\n");
	// printf("test3 %d\n",result3);
	// printf("%d\n", printf("|%i|", 42));
	// printf("\n");

	// printf("test4 :%%s start\n");
	// int result4 = ft_printf("|%s|", "test string");
	// printf("\n");
	// printf("test4 %d\n",result4);
	// printf("%d\n", printf("|%s|", "test string"));
	// printf("\n");

	// int result4_2 = ft_printf("%s", "|\n|");
	// printf("\n");
	// printf("test4_2 %d\n",result4_2);
	// printf("%d", printf("%s", "|\n|"));
	// printf("\n");

	// int result4_3 = ft_printf("%s", "aaa bbbb ccc");
	// printf("\n");
	// printf("test4_3 %d\n",result4_3);
	// printf("%d", printf("%s", "aaa bbbb ccc"));
	// printf("\n");

	// printf("test5 :%%u start\n");
	// int result5 = ft_printf("|%u|", 42);
	// printf("\n");
	// printf("test5 %d\n",result5);
	// printf("%d\n", printf("|%u|", 42));
	// printf("\n");

	// int result5_2 = ft_printf("|%u|", 0);
	// printf("\n");
	// printf("test5_2 %d\n",result5_2);
	// printf("%d\n", printf("|%u|", 0));
	// printf("\n");

	// int result5_3 = ft_printf("|%u|", UINT_MAX);
	// printf("\n");
	// printf("test5_3 %d\n",result5_3);
	// printf("%d\n", printf("|%u|", UINT_MAX));
	// printf("\n");

	// printf("test6 :%%%% start\n");
	// int result6 = ft_printf("aaa%%bbb   %%    ");
	// printf("\n");
	// printf("test6 %d\n",result6);
	// printf("%d\n", printf("aaa%%bbb   %%    "));
	// printf("\n");

	// printf("test7 :%%x start\n");
	// int result7 = ft_printf("|%x|", 42);
	// printf("\n");
	// printf("test7 %d\n",result7);
	// printf("%d\n", printf("|%x|", 42));
	// printf("\n");

	// int result7_2 = ft_printf("|%x|", 15);
	// printf("\n");
	// printf("test7_2 %d\n",result7_2);
	// printf("%d\n", printf("|%x|", 15));
	// printf("\n");

	// int result7_3 = ft_printf("|%x|", -42);
	// printf("\n");
	// printf("test7_3 %d\n",result7_3);
	// printf("%d\n", printf("|%x|", -42));
	// printf("\n");

	// printf("test8 :%%X start\n");
	// int result8 = ft_printf("|%X|", 42);
	// printf("\n");
	// printf("test8 %d\n",result8);
	// printf("%d\n", printf("|%X|", 42));
	// printf("\n");

	// int result8_2 = ft_printf("|%X|", 15);
	// printf("\n");
	// printf("test8_2 %d\n",result8_2);
	// printf("%d\n", printf("|%X|", 15));
	// printf("\n");

	// int result8_3 = ft_printf("|%X|", -42);
	// printf("\n");
	// printf("test8_3 %d\n",result8_3);
	// printf("%d\n", printf("|%X|", -42));
	// printf("\n");

	// printf("test9 :%%p start\n");
	// char *str = "aaaa";
	// int result9 = ft_printf("|%p|", &str);
	// printf("\n");
	// printf("test9 %d\n",result9);
	// printf("%d\n", printf("|%p|", &str));
	// printf("\n");

	// char *str2 = NULL;
	// int result9_2 = ft_printf("|%p|", str2);
	// printf("\n");
	// printf("test9_2 %d\n",result9_2);
	// printf("%d\n", printf("|%p|", str2));
	// printf("\n");

	// ft_printf("%s", (char *)NULL);
	// printf("\n");
	// printf("%s", (char *)NULL);
	// printf("\n");
	// ft_printf("%p", "");
	// printf("\n");
	// printf("%p", "");
	// printf("\n");
	// printf("%        d\n", 25);
	// printf("\n");
	// ft_printf("%        d\n", 25);
	// printf("\n");
	printf("%d\n", printf("%c%s%p%d%i%u%x%X%%\n", 'a', "", "", -42, 42, 25, 50, 50));
	printf("\n");
	printf("%d\n", ft_printf("%c%s%p%d%i%u%x%X%%\n", 'a', "", "", -42, 42, 25, 50, 50));
	printf("\n");
	printf("%d\n",printf("%d%d%d\n", INT_MAX, INT_MIN, 0));
	printf("\n");
	printf("%d\n",ft_printf("%d%d%d\n", INT_MAX, INT_MIN, 0));
	printf("\n");

	printf("%d\n",ft_printf("%j AAA", 2));
	printf("%d\n",printf("%j AAA", 2));

	return (0);
}
*/
