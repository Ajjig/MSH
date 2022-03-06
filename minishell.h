#ifndef MINISHELL_H
# define MINISHELL_H

/*  INClUDES  */

# include "LIBFT/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <signal.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <string.h>

/*  DEFINES  */

# define DOUBLE_QUOTE '"'
# define SINGLE_QUOTE '\''
# define RED_OUTPUT '>'
# define RED_INPUT '<'
# define RED_PIPE '|'
# define RED_APPEND ">>"
# define MINISHELL "\x1b[32mMinishell $\x1b[37m "
# define SPACE ' '
# define FLAG_HYPHEN '-'
# define REDIRECTIONS ">|<"
# define WHITE_SPACES " \t\v\r\f"

/*  PROGRAMS  */

# define _CD "cd"
# define _ECHO "echo"
# define _EXIT "exit"
# define _PWD "pwd"
# define _ENV "env"
# define _EXPORT "export"
# define _UNSET "unset"

/*  TYPEDEFS  */

typedef struct s_command
{
	char				*redirection;
	int					fds[2];
	char				*other;
	char				*program;
	char				**args;
	char				*output;
	struct s_command	*next;
	char				*options;
	char				**execve;
}				t_command;

typedef struct s_envlist // linked lst
{
	char				*var_name;
	char				*var_content;
	char				*stock;
	struct s_envlist	*next;
}						t_envlist;

/*  PROTOTYPES  */

t_command	*get_cammand(char **buff);
t_command	*init_cmd(char **buff);
void		free_cmd(t_command *command);
char		*__cd__(t_command *command, t_envlist *lst);
void		__exec__(t_command *command, t_envlist *lst);
char		*__cwd__(t_command *commad);
char		*__next__(char *str);
char		**args_splitter(char *s);


char		*__echo(t_command *commad);
t_envlist	*__env__init(char **envp);
char		*__env(t_envlist *lst);
char		*__export(t_envlist *lst, t_command *command);

t_envlist	*ft_lstnew(char *s);
t_envlist	*ft_lstlast(t_envlist *lst);
void		ft_lstadd_back(t_envlist **lst, t_envlist *new);

char		*exeve_handler(t_command *command, t_envlist *lst);
int			signal_handler();
#endif
