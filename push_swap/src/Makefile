NAME = push_swap.a
SRCS = parse_utils.c \
		push_swap.c \
		radix_sort.c \
		sort_utils.c \
		swap_rule.c \
		swap_rule_1.c \
		utils_node.c \
		utils.c \
		array_copy.c \
		branch_sort.c 

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
