#include "minishell.h"

t_command	*get_next_cmd(void)
{
	char		*read;
	t_command	*command;

	read = readline(MINISHELL);
	command = get_cammand(read);
	free(read);
	return command;
}

void	free_cmd(t_command *command)
{
	while (command)
	{
		free(command -> program);
		free(command -> args);
		free(command -> options);
		free(command -> redirection);
		free(command);
		command = command -> next;
	}
}

int	main(void)
{
	t_command	*command;

	while (true)
	{
		command = get_next_cmd();
		__exec__(command);
		if (command -> program != NULL && ft_strcmp(command -> program, "exit") == 0)
		{
			free_cmd(command);
			exit(0);
		}
		printf("command == %s\nOprions == %s\nargs   == %s\n", command -> program, command -> options, command -> args);
		free_cmd(command);
	}
}
