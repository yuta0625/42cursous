NAME = libftprintf.a
SRCS = ft_printf.c \
		ft_putchar.c \
		ft_puthex_lowercase.c \
		ft_puthex_uppercase.c \
		ft_putnbr.c \
		ft_putptr.c \
		ft_putstr.c \
		ft_putunnbr.c \
		ft_itoa_hex.c \
		ft_itoa_hex_toupper.c \
		ft_itoa_plus.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
RCS = rcs
RM = rm -f

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(RM) $(NAME)
	cp $(LIBFT) $(NAME)
	$(AR) $(RCS) $(NAME) $(OBJS)

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
