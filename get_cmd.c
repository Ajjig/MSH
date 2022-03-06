#include "minishell.h"

char	*__next__(char *str)
{
	int		len;
	char	*next;

	len = 0;
	while (ft_strchr(WHITE_SPACES, *str) && *str)
		str++;
	if (ft_strchr("><", str[len]))
	{
		len = 1;
		if (str[len] == str[len + 1])
			len++;
	}
	else if (str[len] == '|')
		len = 1;
	else
	{
		while (!ft_strchr(REDIRECTIONS, str[len]) && !ft_strchr(WHITE_SPACES, str[len]) && str[len])
		{
			if (str[len] == DOUBLE_QUOTE)
				while (str[++len] != DOUBLE_QUOTE && str[len]){}
			else if (str[len] == SINGLE_QUOTE)
				while (str[++len] != SINGLE_QUOTE && str[len]){}
			len ++;
		}
	}
	if (len == 0)
		return NULL;
	next = (char *) malloc ((len + 1) * sizeof(char));
	ft_strlcpy(next, str, len + 1);
	return (next);
}

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


t_command	*get_cammand(char **buff)
{
	int			i;
	t_command	*command;
	int			ai;
	int			loop;

	ai = 0;

	i = 0;
	loop = 0;
	command = init_cmd(buff);
	while(buff[i])
	{
		command -> program = is_in_list(buff[i]);
		i++;
		while (buff[i] && buff[i][0] == FLAG_HYPHEN)
		{
			free(command -> options);
			command -> options = ft_strjoin(command -> options, buff[i++]);
		}
		if (buff[i] && ft_strchr(REDIRECTIONS, buff[i][0]))
			command -> redirection = ft_strdup(buff[i++]);
		while (buff[i])
			command -> args[ai++] = ft_strdup(buff[i++]);
	}
	command ->args[ai] = NULL;
	command -> all = buff;
	return command;
}
