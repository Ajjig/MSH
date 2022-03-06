#include "minishell.h"

t_command	*init_cmd(char **buff)
{
	int			len;
	t_command	*command = NULL;

	len = 0;
	while (buff[len])
		len++;
	command = (t_command *) malloc (sizeof(t_command));
	command -> args = (char **) malloc ((len + 1) * sizeof(char *));
	command -> program = NULL;
	command -> next = NULL;
	command -> redirection = NULL;
	command -> options = NULL;
	return (command);
}
