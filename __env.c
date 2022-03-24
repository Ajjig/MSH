#include "minishell.h"

int	__env(t_envlist *lst)
{
	if (!lst)
		return 1;
	while (lst != NULL)
	{
		printf("%s=%s\n", lst->var_name, lst->var_content);
		lst = lst->next;
	}
	return 0;
}

t_envlist *__env__init(char **envp)
{
	int i;
	t_envlist *lst;

	lst = NULL;
	i  = 0;
	if(envp[0] == NULL)
	{
		ft_lstadd_back(&lst, ft_lstnew("PATH=/usr/local/bin:/bin:/usr/bin:."));
		return lst;
	}
	while (envp[i])
	{
		ft_lstadd_back(&lst, ft_lstnew(envp[i]));
		i++;
	}
	return lst;
}
