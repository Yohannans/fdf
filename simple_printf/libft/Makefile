SRC = $(addsuffix .c, ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint \
	  ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy ft_strlcat \
	  ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp \
	  ft_strnstr ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split \
	  ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
	  ft_atoi ft_itoa)
BONUS_SRC = $(addsuffix _bonus.c, ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast \
			ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap)
OBJS := $(SRC:%.c=%.o)
BONUS_OBJS := $(BONUS_SRC:%.c=%.o)
NAME = libft.a
CC = cc
CCFLAGS = -Wall -Wextra -Werror
INC_DIR = .
RM = rm -f
ARNAME = ar rcs $(NAME)
OBJS_ALL = $(OBJS) $(BONUS_OBJS)

all: $(NAME)

$(NAME): $(OBJS)
	$(ARNAME) $(OBJS)

%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS_ALL)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJS_ALL)
	$(ARNAME) $(OBJS_ALL)

.PHONY: all clean fclean re bonus
