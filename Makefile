NAME = minishell
LIBFT = LIBFT/libft.a
INC = minishell.h
CFLAGS = -Wall -Wextra -Werror -g -lreadline
RM = rm -rf
CC = cc

CFILES = minishell.c get_cmd.c command_init.c exec.c cd.c cwd.c __echo.c __env.c list_lib.c __export.c \
		args_splitter.c sig_handler.c execve.c __unset.c split.c quotes.c \
		files.c get_execve.c error_handler.c getenv.c pipe_handler.c redirection_handler.c \
		parser.c is_builtin.c str_join.c free_lst.c

FILES = $(addprefix src/, $(CFILES))

OBJS = $(FILES:.c=.o)

all: $(NAME)
	

$(NAME): $(OBJS) $(LIBFT)
	@$(CC)  $(OBJS) $(LIBFT) $(CFLAGS)  -o $(NAME)
	@echo "minishell created"

$(LIBFT):
	@make -C LIBFT/

%.o:%.c 
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "compiling minishell ..."



clean:
	@$(RM) $(OBJS)
	@make clean -C LIBFT/
	@echo "successfuly cleaned"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C LIBFT/
	@echo "executable removed successfuly"

re: fclean all
