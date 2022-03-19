#include "minishell.h"

void	gen_fds(t_command *command, int fd)
{
	t_fds	*new;

	new = (t_fds *) malloc (sizeof(t_fds));
	new -> fd = fd;
	new -> next = NULL;
	if (command -> fds == NULL)
	{
		command -> fds = new;
		return ;
	}
	while (command -> fds -> next)
		command -> fds = command -> fds -> next;
	command -> fds -> next = new;
}
