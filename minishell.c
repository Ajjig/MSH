#include "minishell.h"

t_command	*get_next_cmd(void)
{
	char		*read;
	t_command	*command;
	char		**buff;
	int			i;

	i = 0;
	read = readline(MINISHELL);
	if (ft_strlen(read) > 0)
		add_history(read);
	buff = args_splitter(read);
	command = get_cammand(buff);
	while (buff[i])
		free(buff[i++]);
	free(buff);
	free(read);
	return command;
}

void	free_cmd(t_command *command)
{
	int	i;

	i = 0;
	free(command -> program);
	while (command -> args && command -> args[i])
		free(command -> args[i++]);
	free(command -> args);
	free(command -> options);
	free(command -> redirection);
	free(command);
}

int	main(int ac, char **av, char **envp)
{
	t_command	*command;
	t_envlist	*lst;

	av = NULL;
	lst = __env__init(envp);
	while (true)
	{
		ac = 0;
		command = get_next_cmd();
		__exec__(command, lst);
		if (command -> program != NULL && ft_strcmp(command -> program, "exit") == 0)
		{
			free_cmd(command);
			exit(0);
		}
		while (command -> args && command -> args[ac])
			printf("args === %s\n", command -> args[ac++]);
		free_cmd(command);
		command = NULL;
	}
}
