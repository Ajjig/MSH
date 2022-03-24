#include "minishell.h"

void pipe_close(t_command *tmp, int fd0, int fd1)
{
	if (tmp->next)
	{
		dup2(fd0, 0);
		close(fd0);
		close(fd1);
	}
}

void pipe_utils(t_command *tmp, t_envlist *lst)
{
	int pid;
	int fd[2];

	if (tmp->next)
		pipe(fd);
	pid = fork();
	if (pid < 0)
		perror("error\n");
	if (pid == 0)
	{
		if (tmp->next)
		{
			close(1);
			dup2(fd[1], 1);
			close(fd[1]);
			close(fd[0]);
		}
		redirection_handler(tmp, lst);
		__exec__(tmp, lst);
		exit(0);
	}
	close(0);
	pipe_close(tmp, fd[0], fd[1]);
}

void pipe_handler(t_command *command, t_envlist *lst)
{
	int save_stdout = dup(0);
	t_command *tmp;
	int		exits;

	tmp = command;
	while (tmp)
	{
		pipe_utils(tmp, lst);
		tmp = tmp->next;
	}
	tmp = command;
	while (tmp)
	{
		wait(&exits);
		if (WIFSIGNALED(exits))
		{
			if (WTERMSIG(exits) != 13)
				g_exites = 128 + WTERMSIG(exits);
			if (WTERMSIG(exits) == SIGQUIT)
				printf(" Quit\n");
		}
		else
			g_exites = WEXITSTATUS(exits);
		tmp = tmp->next;
	}
	close(0);
	dup2(save_stdout, 0);
	close(save_stdout);
}
