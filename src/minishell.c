/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:14:03 by iidkhebb          #+#    #+#             */
/*   Updated: 2022/10/14 22:29:57 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


#include <readline/readline.h>
#include <readline/history.h>

t_command	*get_next_cmd(t_envlist *lst)
{
	char		*read;
	t_command	*command;
	char		**buff;

	if (g_variable.g_exites != 0)
		read = readline(MINISHELL_RED);
	else
		read = readline(MINISHELL_GREEN);
	if (!read)
	{
		printf("exit");
		exit(1);
	}
	if (ft_strlen(read) > 0)
		add_history(read);
	read = __get_env(read, lst, 0);
	buff = args_splitter(NULL, read, 0, 0);
	if (error_checker(buff) == false)
		return (NULL);
	if (!buff || buff[0] == NULL)
		return (NULL);
	return (free(read), command = get_cammand(buff, -1, 0, lst), command);
}

void	free_cmd(t_command *command)
{
	int	i;

	i = 0;
	if (!command)
		return ;
	free(command -> program);
	while (command -> args && command -> args[i])
		free(command -> args[i++]);
	i = 0;
	while (command -> execve[i])
		free(command -> execve[i++]);
	while (command -> files)
	{
		free(command -> files -> file);
		free(command -> files);
		command -> files = command -> files -> next;
	}
	free(command -> execve);
	free(command -> args);
	free(command -> options);
	free(command -> redirection);
	free(command);
	command = command->next;
	free_cmd(command);
}

void	command_roots(t_command *command, t_envlist *lst)
{
	g_variable.is_running = 1;
	if (command->next || command->redirection)
		pipe_handler(command, lst);
	else
		__exec__(command, lst);
	g_variable.is_running = 0;
}

void	__exit(t_command *command)
{
	if (command && command -> program != NULL \
		&& ft_strcmp(command -> program, "exit") == 0)
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

	(void)av,(void)ac;
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
	return (0);
}
