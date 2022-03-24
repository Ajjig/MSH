#include "minishell.h"

int check_exp_arg(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (ft_isalpha(s[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

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
	char *tmp;

	tmp = NULL;
	out = NULL;
	if (command->args[i] == NULL)
		return out;
	if (ft_strchr(command->args[i], '+') == NULL)
	{
		command->is_append = 0;
		out = ft_split_smart(command->args[i], '=');
		if (!ft_isalpha(out[0][0]) && out[0][0] != '_')
			return (printf("export: `%s' : not a valid identifier\n", out[0]), NULL);
		else if (!ft_strcmp(command->args[i], out[0]))
			return NULL;
	}
	else if (ft_strchr(command->args[i], '+') != NULL)
	{
		command->is_append = 1;
		out = ft_split_smart(command->args[i], '+');
		tmp = out[1];
		out[1] = ft_strdup(ft_strchr(out[1], '=') + 1);
		free(tmp);
	}
	return out;
}

void __export_utils(char **tab, t_envlist *lst, t_command *command)
{
	t_envlist *tmp;
	char *to_free;

	tmp = lst;
	to_free = NULL;
	while (tmp != NULL)
	{
		if(!ft_strcmp(tmp->var_name, tab[0]) && command->is_append == 0) // NO APPEND
		{
			free(tmp->var_content);
			tmp->var_content = ft_strdup(tab[1]);
			return ;
		}
		else if (!ft_strcmp(tmp->var_name, tab[0]) && command->is_append == 1) // APPEND
		{
			to_free = tmp->var_content;
			tmp->var_content = ft_strjoin(tmp->var_content, tab[1]);
			free(to_free);
			return ;
		}
		tmp = tmp->next;
	}
	ft_lstadd_back(&lst, ft_lstnew_2(tab));
}

char *export_printer(t_envlist *lst)
{
	if (!lst)
		return NULL;
	while (lst != NULL)
	{
		printf("declare -x %s=\"%s\"\n", lst->var_name, lst->var_content);
		lst = lst->next;
	}
	return NULL;
}

char *__export(t_envlist *lst, t_command *command)
{
	char **tab;
	int tablen;
	int i;

	i = 0;
	tablen = 0;
	if (!command->args || !command->args[0])
		return export_printer(lst);
	tablen = ft_tab_len(command->args);

	while (tablen != 0)
	{
		tab = export_spliter(command, i);
		if (!tab)
			return NULL;
		__export_utils(tab, lst, command);
		tablen--;
		i++;
		free(tab[0]);
		free(tab[1]);
		free(tab);
	}
	return NULL;
}
