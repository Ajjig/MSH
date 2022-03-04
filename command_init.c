#include "minishell.h"

t_command	*init_cmd(void)
{
	t_command	*command;

	command = (t_command *) malloc (sizeof(t_command));
	command -> program = NULL;
	command -> next = NULL;
	command -> redirection = NULL;
	command -> options = NULL;
	command -> args = NULL;
	return (command);
}
