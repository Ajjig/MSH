#include "minishell.h"

char *__env(t_envlist *lst)
{
	if (!lst)
		return NULL;
	while (lst != NULL)
	{
		printf("%s=%s\n", lst->var_name, lst->var_content);
		lst = lst->next;
	}
	return NULL;
}

t_envlist *__env__init(char **envp) // hadi kat 9ad list
{
	int i;
	t_envlist *lst;

	lst = NULL;
	i  = 0;
	if(!envp)
		return lst;
	while (envp[i])
	{
		ft_lstadd_back(&lst, ft_lstnew(envp[i]));
		//printf("%s\n", envp[i++]);
		i++;
	}
	return lst;
}
