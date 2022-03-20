#include "minishell.h"

char	*path_joiner(char *path, char *cmd)
{
	char	*ret;
	char	*slash;

	slash = ft_strjoin(path, "/");
	ret = ft_strjoin(slash, cmd);
	free(slash);
	return (ret);
}

char	*is_in_list(char *cmd)
{
	static char	*all[] = {"echo", "cd", "pwd", "export", "unset", "env", "exit"};
	char		**others;
	char		*path;
	int			i;

	i = 0;
	while (i < 7)
		if (ft_strcmp(all[i++], cmd) == 0)
			return (ft_strdup(all[--i]));
	if (ft_strchr(cmd, '/') && access(cmd, F_OK) != -1)
		return (ft_strdup(cmd));
	path = getenv("PATH");
	others = ft_split(path, ':');
	i = 0;
	while (others[i])
	{
		path = path_joiner(others[i++], cmd);
		if (access(path, F_OK) != -1)
		{
			i = 0;
			while (others[i])
				free(others[i++]);
			free(others);
			return (path);
		}
		free(path);
	}
	i = 0;
	while (others[i])
		free(others[i++]);
	free(others);
	return (NULL);
}

char	*args_joiner(char *args, char *new)
{
	char	*joined;
	char	*space;

	if (args == NULL)
		return (ft_strdup(new));
	space = ft_strjoin(args, " ");
	joined = ft_strjoin(space, new);
	free(args);
	free(space);
	return (joined);
}


t_command	*get_cammand(char **buff, int i)
{
	t_command	*command;
	int			ai;
	int			tmp;

	tmp = i;
	ai = 0;
	if (buff[i] == NULL)
		return (NULL);
	command = init_cmd(buff);
	command -> program = is_in_list(buff[i++]);
	while (buff[i])
	{
		if (buff[i][0] == RED_PIPE)
		{
			command -> args[ai] = NULL;
			command -> execve = get_execve(buff, tmp);
			command -> next = get_cammand(buff, ++i);
			return (command);
		}
		if (ft_strchr(REDIRECTIONS, buff[i][0]))
		{
			command -> redirection = ft_strdup(buff[i]);
			gen_files(command, buff[++i]);
			break ;
		}
		command -> args[ai++] = ft_strdup(buff[i++]);
	}
	command -> args[ai] = NULL;
	command -> execve = get_execve(buff, tmp);
	return command;
}
