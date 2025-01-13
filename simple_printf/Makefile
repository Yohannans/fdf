SRC = $(addprefix src/, $(addsuffix .c, ft_printf print_char print_str \
	  									print_ptr print_int print_uint \
										print_hex_lc print_hex_uc))
LIBFT = libft
OBJS := $(SRC:%.c=%.o)
DEPS := $(OBJS:%.o=%.d)
NAME = libftprintf.a
INCLUDE = -I includes
CC = cc
CCFLAGS = -Wall -Werror -Wextra -Iinclude
RM = rm -f
ARNAME = ar rcs 

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT) bonus
	cp $(LIBFT)/libft.a .
	$(ARNAME) libft.a $(OBJS)
	mv libft.a $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDE) -MMD -MP -o $@ -c $< 
-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)
	make -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
