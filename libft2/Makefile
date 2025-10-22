# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/16 10:32:14 by yohya             #+#    #+#              #
#    Updated: 2025/10/22 16:36:42 by yohya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memset.c \
		ft_memcpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memmove.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_substr.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

BONUS_SRCS = ft_lstnew.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(NAME) $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)
clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
