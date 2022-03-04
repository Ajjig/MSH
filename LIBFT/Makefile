# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majjig <majjig@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 15:31:37 by majjig            #+#    #+#              #
#    Updated: 2022/02/26 11:38:01 by majjig           ###   ########.fr        #
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

BNS = ft_lstnew.c \
	  ft_lstadd_front.c \
	  ft_lstsize.c \
	  ft_lstlast.c \
	  ft_lstadd_back.c \
	  ft_lstdelone.c \
	  ft_lstclear.c \
	  ft_lstiter.c \
	  ft_lstmap.c

OBJS = ${SRCS:.c=.o}

OBJSBNS = ${BNS:.c=.o}

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

NAME = libft.a

bonus: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(SRCS) $(BNS)
	@ar rc $(NAME) $(OBJS)
lib:
	@ar rc $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	@rm -f $(OBJSBNS)

fclean: clean
	@rm -f $(NAME)

re: fclean bonus
