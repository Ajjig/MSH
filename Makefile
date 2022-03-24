
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

INC = minishell.h

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
		get_execve.c \
		error_handler.c \
		getenv.c \
		pipe_handler.c \
		redirection_handler.c

OBJS =	${SRC:.c=.o}

LIBNAME = LIBFT/libft.a

CFLAGS = -Wall -Werror -Wextra -g
CFLAGS += -lreadline
CFLAGS += -I$(shell brew --prefix readline)/include
ANIMATION = curl -s "http://artscene.textfiles.com/vt100/monorail.vt" | pv -q -L 6600
CC = gcc

all: display libft $(NAME)

$(NAME): $(OBJS) $(INC)
	$(CC) $(CFLAGS) -L$(shell brew --prefix readline)/lib $(SRCS) $(LIBNAME) -o $(NAME)

libft:
	@make -C LIBFT/
	@echo "\x1b[33mLIBFT compiled successfully\x1b[37m"
display:
	-@$(shell brew install readline)
	-@$(shell brew install pv)

	clear
	@echo "\x1b[36m	__  __  ___  _   _  ___  ____   _   _  _____  _      _      "
	@echo "	|  \/  ||_ _|| \ | ||_ _|/ ___| | | | || ____|| |    | |"
	@echo "	| |\/| | | | |  \| | | | \___ \ | |_| ||  _|  | |    | |"
	@echo "	| |  | | | | | |\  | | |  ___) ||  _  || |___ | |___ | |___"
	@echo "	|_|  |_||___||_| \_||___||____/ |_| |_||_____||_____||_____|"

clean:v
	-@rm -fr $(OBJS)
	-@make clean -C LIBFT/

fclean: clean
	-@rm -fr $(NAME)
	-@make fclean -C LIBFT/

re: fclean all

.PHONY: libft $(NAME)
