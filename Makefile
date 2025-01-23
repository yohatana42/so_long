# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/08 14:55:25 by yohatana          #+#    #+#              #
#    Updated: 2025/01/23 22:26:11 by yohatana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name
NAME		= so_long

# src files
SRCS		=\
				get_next_line/get_next_line.c\
				get_next_line/get_next_line_utils.c\
				validation_argument.c\
				validation_map.c\
				validation_map_helper.c\
				validation_argument_helper.c\
				collect_list.c\
				create_map_struct.c\
				error.c\
				search_route_c.c\
				search_map_route.c\
				create_game_struct.c\
				create_struct.c\
				game_init.c\
				game_event.c\
				game_print.c\
				all_collect_get_check.c\
				main.c


# object file name
OBJS		= $(SRCS:.c=.o)

# compile flag
CC			= cc
CCFLAGS		= -Wall -Wextra -Werror

# Archive and remove command
AR			= ar rcs
RM			= rm -f

.DEFAULT:	all

all:		$(NAME)

# libft
LIBFT = libft
$(LIBFT)/libft.a:
		make -C $(LIBFT)

# printf
PRINTF = printf
$(PRINTF)/libftprintf.a:
		make -C $(PRINTF)

# minilibX
MLX = minilibx-linux
$(MLX)/libmlx_Linux.a:
		make -C $(MLX)

%.o: %.c
		$(CC) $(CCFLAGS) -I$(LIBFT) -I$(PRINTF) -I$(MLX) -c $< -o $@

${NAME}:	${OBJS} $(MLX)/libmlx_Linux.a $(PRINTF)/libftprintf.a $(LIBFT)/libft.a
			$(CC) ${OBJS} -L$(LIBFT) -lft -L$(PRINTF) -lftprintf -L$(MLX) -lmlx -lm -lXext -lX11 -o $(NAME)

clean:
			make -C $(PRINTF) clean
			make -C $(LIBFT) clean
			make -C $(MLX) clean
			${RM} $(OBJS)

fclean:		clean
			make -C $(LIBFT) fclean
			make -C $(PRINTF) fclean
			${RM} $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
