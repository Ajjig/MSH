#include "minishell.h"

int heredoc(t_command *command, t_envlist *lst)
{
	char *prompt;
	int fd[2];

	pipe(fd);
	while (1)
	{
		prompt = readline("\x1b[34mheredoc > \x1b[37m");
		if (!prompt || !ft_strcmp(command->files->file, prompt))
			return (free(prompt), close(fd[1]) ,fd[0]);
		ft_putstr_fd(__get_env(prompt, lst), fd[1]);
		ft_putstr_fd("\n", fd[1]);
	}
}

void right_redirection(t_command *command, int file_out)
{
	if (!ft_strcmp(command->redirection, ">"))
	{
		file_out = open(command->files->file, O_CREAT | O_RDWR | O_TRUNC, 0666);
		dup2(file_out, 1);
		close(file_out);
	}
	else if (!ft_strcmp(command->redirection, ">>"))
	{
		file_out = open(command->files->file, O_CREAT | O_RDWR | O_APPEND, 0666);
		dup2(file_out, 1);
		close(file_out);
	}
}

void left_redirection(t_command *command, int file_out)
{
	if (!ft_strcmp(command->redirection, "<"))
	{
		file_out = open(command->files->file, O_RDONLY);
		dup2(file_out, 0);
		close(file_out);

	}
	else if (!ft_strcmp(command->redirection, "<<"))
	{
		dup2(command->heredoc, 0);
		close(command->heredoc);
	}
}
void redirection_handler(t_command *command, t_envlist *lst)
{
	int file_out;

	file_out = 0;
	if (command->files != NULL)
	{
		right_redirection(command, file_out);
		left_redirection(command, file_out);
		command->files = command->files->next;
		redirection_handler(command, lst);
	}
}
