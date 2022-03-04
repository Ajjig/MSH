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
	char				*args;
	char				*output;
	struct s_command	*next;
	char				*options;
}				t_command;

/*  PROTOTYPES  */

t_command	*get_cammand(char *read);
t_command	*init_cmd(void);
void		free_cmd(t_command *command);
char		*__cd__(t_command *command);
void		__exec__(t_command *command);
char		*__cwd__(t_command *commad);

#endif
