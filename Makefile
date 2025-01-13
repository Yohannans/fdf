CC = cc
NAME = fdf
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = simple_printf/libftprintf.a	
GNL = $(addprefix get_next_line/, $(addsuffix _bonus.c, get_next_line get_next_line_utils))
MLX = minilibx-linux/libmlx_Linux.a
SRC = $(addsuffix .c, main openfile point_utils draw_utils rotation) $(GNL)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C simple_printf
	$(MAKE) -C minilibx-linux
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX) -lXext -lX11 -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C simple_printf clean
	$(MAKE) -C minilibx-linux clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C simple_printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re