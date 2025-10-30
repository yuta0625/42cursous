NAME = libftprintf.a
SRCS = ft_printf.c \
		ft_putchar.c \
		ft_puthex_lowercase.c \
		ft_puthex_uppercase.c \
		ft_putnbr.c \
		ft_putptr.c \
		ft_putstr.c \
		ft_putunnbr.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = src
LIBFT     = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	ar -x $(LIBFT)
	$(AR) $(NAME) $(OBJS) *.o
	$(RM) libft.a *.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
