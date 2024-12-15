# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/08 14:55:25 by yohatana          #+#    #+#              #
#    Updated: 2024/12/15 18:53:11 by yohatana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name
NAME		= so_long

# src files
SRCS		=\
				get_next_line/get_next_line.c\
				get_next_line/get_next_line_utils.c\
				main.c\
				map_check.c\
				map_check_helper.c\
				all_free.c


# object file name
OBJS		= $(SRCS:.c=.o)
%o: %c
		$(CC) $(CCFLAGS) -I$(LIBFT) -I$(PRINTF) -I$(MLX) -c $< -o $@

# compile flag
CC			= cc
CCFLAGS		= -Wall -Wextra -Werror

# Archive and remove command
AR			= ar rcs
RM			= rm -f

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
