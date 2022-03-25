#include "minishell.h"

t_command	*get_next_cmd(t_envlist *lst)
{
	char		*read;
	t_command	*command;
	char		**buff;
	int			i;

	i = 0;
	if(g_variable.g_exites != 0)
		read = readline(MINISHELL_RED);
	else
		read = readline(MINISHELL_GREEN);
	if (!read)
	{
		puts("exit");
		exit(1);
	}
	if (ft_strlen(read) > 0)
		add_history(read);
	read = __get_env(read, lst);
	buff = args_splitter(read);
	if (error_checker(buff) == false)
		return (NULL);
	command = get_cammand(buff, 0, lst);
	free(read);
	return command;
}

void	free_cmd(t_command *command)
{
	int	i;

	i = 0;
	if (command == NULL)
		return ;
	free(command -> program);
	while (command -> args && command -> args[i])
		free(command -> args[i++]);
	i = 0;
	while (command -> execve[i])
		free(command -> execve[i++]);
	free(command -> execve);
	free(command -> args);
	free(command -> options);
	free(command -> redirection);
	free(command);
}

void command_roots(t_command *command, t_envlist *lst)
{
	g_variable.is_running = 1;
	if (command->next || command->redirection)
		pipe_handler(command, lst);
	else
		__exec__(command, lst);
	g_variable.is_running = 0;
}

void __exit(t_command *command)
{
	if (command && command -> program != NULL && ft_strcmp(command -> program, "exit") == 0)
	{
		write(1, "exit\n", 5);
		free_cmd(command);
		exit(1);
	}
	return ;
}

int	main(int ac, char **av, char **envp)
{
	t_command	*command;
	t_envlist	*lst;

	av = NULL;
	lst = __env__init(envp);
	signal_handler();
	while (true)
	{
		ac = 0;
		command = get_next_cmd(lst);
		__exit(command);
		if (command)
			command_roots(command, lst);
		free_cmd(command);
		command = NULL;
	}
	rl_clear_history();
	return 0;
}
