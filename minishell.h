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
# define MINISHELL "➜ \x1b[35mMinishell $\x1b[37m "
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

typedef struct s_files
{
	char			*file;
	struct s_files	*next;
	bool			is_append;
}				t_files;


typedef struct s_command
{
	char				*redirection;
	t_files				*files;
	char				*other;
	char				*program;
	char				**args;
	char				*output;
	struct s_command	*next;
	char				*options;
	char				**execve;
	int					flags;
	int					is_append;
	int					heredoc;

}				t_command;

typedef struct s_envlist // linked lst
{
	char				*var_name;
	char				*var_content;
	char				*stock;
	struct s_envlist	*next;
}						t_envlist;

/*  PROTOTYPES  */

t_command	*get_cammand(char **buff, int i, t_envlist *lst);
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
int			ft_tab_len(char **tab);
char		*__unset(t_command *commad, t_envlist *lst);
char		**ft_split_smart(char const *s, char c);
char		*check_quotes(char	*str);
void		gen_files(t_command *command, char *red, char *file);
char		**get_execve(char **buff, int i);
bool		error_checker(char **buff);
char		*__get_env(char *read, t_envlist *lst);


void pipe_handler(t_command *command, t_envlist *lst);
void redirection_handler(t_command *command, t_envlist *lst);
int heredoc(t_command *command, t_envlist *lst);

#endif
