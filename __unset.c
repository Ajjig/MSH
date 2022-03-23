#include "minishell.h"
void unset_utils(t_envlist *lst, char *tab)
{
	while (lst != NULL)
	{
		if (lst->next && !ft_strcmp(lst->next->var_name, tab))
		{
			free(lst->next);
			lst->next = lst->next->next;
			return ;
		}
		lst = lst->next;
	}
}

char *__unset(t_command *commad, t_envlist *lst)
{
	int tablen;
	int i;
	t_envlist *tmp;

	if (!commad->args)
		return NULL;
	i = 0;
	tablen = ft_tab_len(commad->args);
	while (i < tablen)
	{
		tmp = lst;
		unset_utils(tmp, commad->args[i]);
		i++;
	}
	return NULL;
}
