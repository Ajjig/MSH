#include "minishell.h"
t_envlist	*ft_lstnew_2(char **s)
{
	t_envlist	*new;

	new = (t_envlist *)malloc(sizeof(t_envlist));
	if (!(new))
		return (0);
	new->var_name = ft_strdup(s[0]);
	new->var_content = ft_strdup(s[1]);
	new->stock = NULL;
	new->next = NULL;
	return (new);
}

int ft_tab_len(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return i;
}

char **export_spliter(t_command *command, int i)
{
	char **out;

	out = NULL;
	if (command->args[i] == NULL)
		return out;
	if (ft_strchr(command->args[i], '=') != NULL)
	{
		out = ft_split(command->args[i], '=');
	}
	// else if (ft_strchr(command->args[i], '+') != NULL)
	// {
	// 	out = ft_split(command->args[i], '+');
	// }
	return out;
}

void __export_utils(char **tab, t_envlist *lst)
{
	t_envlist *tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if(!ft_strcmp(tmp->var_name, tab[0]))
		{
			free(tmp->var_content);
			tmp->var_content = ft_strdup(tab[1]);
			return ;
		}
		tmp = tmp->next;
	}
	ft_lstadd_back(&lst, ft_lstnew_2(tab));
}

char *__export(t_envlist *lst, t_command *command)
{
	char **tab;
	int tablen;
	int i;

	i = 0;
	tablen = 0;

	if (!command->args)
		return NULL;

	tablen = ft_tab_len(command->args);

	while (tablen != 0)
	{
		tab = export_spliter(command, i);
		__export_utils(tab, lst);
		tablen--;
		i++;
		free(tab[0]);
		free(tab[1]);
		free(tab);
	}

	return NULL;
}
