#include "minishell.h"


int __pipe(char *av[])
{
	int fd[2];

	if (pipe(fd) == -1)
		return 0;
}


int main(int argc, char const *argv[], char **envp)
{
	int fd[2];
	int pid1;
	int pid2;

	if (pipe(fd) == -1)
		return 0;
	pid1 = fork();
	char *const buff[] = {"echo", "heloo 5 8 1", NULL};
	char *const buff2[] = {"grep", "8", NULL};
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve("/bin/echo", buff ,envp);
	}


	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve("/usr/bin/grep", buff2, envp);
	}

	close(fd[0]);
	close(fd[1]);


	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return 0;
}

