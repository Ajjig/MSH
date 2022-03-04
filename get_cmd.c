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
		if (str[len] == str[len + 1])
			len = 2;
		else
			len = 1;
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


t_command	*get_cammand(char *read)
{
	int			i;
	t_command	*command;
	char		*next;
	int			loop;

	i = 0;
	loop = 0;
	command = init_cmd();
	while (read[i])
	{
		next = __next__(&read[i]);
		if (next == NULL)
			return NULL;
		i += ft_strlen(next);
		while (ft_strchr(WHITE_SPACES, read[i]) && read[i])
			i++;
		if (loop == 0)
			command -> program = is_in_list(next);
		else if (loop == 1 && next[0] == FLAG_HYPHEN)
			command -> options = ft_strdup(next);
		else if (ft_strchr(REDIRECTIONS, next[0]))
		{
			command -> redirection = ft_strdup(next);
			break ;
		}
		else if (loop > 1 || (loop == 1 && command -> options == NULL))
			command -> args = args_joiner(command -> args, next);
		free(next);
		loop ++;
	}
	return command;
}
