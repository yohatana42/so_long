# so_long
NAME		=	so_long
SRCS		=	main.c check1.c check2.c map_check1.c map_check2.c game1.c game2.c
OBJS 		=	$(SRCS:.c=.o)
# Compiler
CC			=	cc
#LIBX_FLAGS	=	-lmlx_Linux -lXext -lX11
LIBX_FLAGS	=	-lXext -lX11
CFLAGS		=	-Wall -Wextra -Werror

# Rules
all:			$(NAME)

$(NAME):		$(OBJS)
			make -C libft
			make -C minilibx-linux
			$(CC) $(OBJS) $(LIBX_FLAGS) $(CFLAGS) get_next_line.c get_next_line_utils.c libft/libft.a minilibx-linux/libmlx_Linux.a -o $(NAME)

clean:
			make fclean -C libft
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

norm:
			norminette so_long.h
			norminette $(SRCS)

.PHONY:			all clean fclean re

