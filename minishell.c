#include "minishell.h"

t_command	*get_next_cmd(void)
{
	char		*read;
	t_command	*command;

	read = readline(MINISHELL);
	if (ft_strlen(read) > 0)
		add_history(read);
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

int	main(int ac, char **av, char **envp)
{
	t_command	*command;
	t_envlist	*lst;

	ac = 0;
	av = NULL;

	lst = __env__init(envp);
	while (true)
	{
		command = get_next_cmd();
		command -> argslist = gen_arg_list(command -> args);
		__exec__(command, lst);
		if (command -> program != NULL && ft_strcmp(command -> program, "exit") == 0)
		{
			free_cmd(command);
			exit(0);
		}
		//printf("command == %s\nOptions == %s\nargs   == %s\n", command -> program, command -> options, command -> args);
		free_cmd(command);
	}
}
