NAME	= so_long
SRCS	=	src/so_long.c src/so_long_utils.c src/playing.c src/map_name.c \
			src/map_check.c src/is_valid.c src/img_places.c src/free.c\
			src/get_next_line.c src/get_next_line_utils.c src/ft_printf.c src/component_check.c
OBJS	= $(SRCS:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror # -fsanitize=address -g
MLX		=./mlx/libmlx.a

all: $(MLX) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(SRCS) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
$(MLX): 
	make re -C ./mlx

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) $(MLX)

re: fclean all

.PHONY: all clean fclean re