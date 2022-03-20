#include "minishell.h"

t_command	*init_cmd(char **buff)
{
	int			len;
	t_command	*command = NULL;

	len = 0;
	while (buff[len])
		len++;
	if (buff[1] && !ft_strcmp(buff[0], _ECHO) && buff[1][0] == FLAG_HYPHEN)
		command -> options = ft_strdup(buff[1]);
	command = (t_command *) malloc (sizeof(t_command));
	command -> args = (char **) malloc ((len + 1) * sizeof(char *));
	command -> program = NULL;
	command -> next = NULL;
	command -> redirection = NULL;
	command -> options = NULL;
	command -> files = NULL;
	command -> flags = O_WRONLY | O_CREAT;
	return (command);
}
