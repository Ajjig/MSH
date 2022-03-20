#include "minishell.h"

void	gen_files(t_command *command, char *file)
{
	t_files	*new;

	new = (t_files *) malloc (sizeof(t_files));
	new -> file = ft_strdup(file);
	new -> next = NULL;
	if (command -> files == NULL)
	{
		command -> files = new;
		return ;
	}
	while (command -> files -> next)
		command -> files = command -> files -> next;
	command -> files -> next = new;
}
