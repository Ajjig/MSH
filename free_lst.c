#include "minishell.h"

void	free_lst(t_envlist *lst)
{
	while (lst)
	{
		free(lst -> stock);
		free(lst -> var_content);
		free(lst -> var_name);
		lst = lst -> next;
	}
}
