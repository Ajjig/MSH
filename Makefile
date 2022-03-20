
# COLORS
GREY=$'\x1b[30m
RED=$'\x1b[31m
GREEN=$'\x1b[32m
YELLOW=$'\x1b[33m
BLUE=$'\x1b[34m
PURPLE=$'\x1b[35m
CYAN=$'\x1b[36m
WHITE=$'\x1b[37m

NAME = minishell

SRCS =	minishell.c \
		get_cmd.c \
		command_init.c \
		exec.c \
		cd.c \
		cwd.c \
		__echo.c \
		__env.c \
		list_lib.c \
		__export.c \
		args_splitter.c \
		sig_handler.c \
		execve.c \
		__unset.c \
		split.c \
		quotes.c \
		files.c \
		get_execve.c

OBJS =	${SRC:.c=.o}

LIBNAME = LIBFT/libft.a

CFLAGS = -Wall -Werror -Wextra
CFLAGS += -lreadline
CFLAGS += -I$(shell brew --prefix readline)/include

CC = gcc

all: libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -L$(shell brew --prefix readline)/lib $(SRCS) $(LIBNAME) -o $(NAME)

libft:
	@make -C LIBFT/
	@echo "LIBFT compiled successfully"

run: all
	./minishell

.PHONY: libft $(NAME)
