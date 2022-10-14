# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 15:31:37 by majjig            #+#    #+#              #
#    Updated: 2022/10/14 22:20:48 by tel-mouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  ft_calloc.c \
		ft_isdigit.c \
		ft_memcmp.c \
		ft_strchr.c \
		ft_strlcpy.c \
		ft_isalnum.c \
		ft_isprint.c \
		ft_memcpy.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_substr.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_itoa.c \
		ft_memmove.c \
		ft_strjoin.c \
		ft_strncmp.c \
		ft_tolower.c \
		ft_bzero.c \
		ft_isascii.c \
		ft_memchr.c \
		ft_memset.c \
		ft_strlcat.c \
		ft_strrchr.c \
		ft_toupper.c \
		ft_strnstr.c \
		ft_strtrim.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_split.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strcmp.c

BNS =

OBJS = ${SRCS:.c=.o}

OBJSBNS = ${BNS:.c=.o}

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror -g

NAME = libft.a

bonus: $(NAME)


all : $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $<
# lib:
# 	@ar rc $(NAME) $(OBJS)
# 	clear

clean:
	@rm -f $(OBJS)
	@rm -f $(OBJSBNS)

fclean: clean
	@rm -f $(NAME)

re: fclean bonus
