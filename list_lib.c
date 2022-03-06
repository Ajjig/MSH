#include "minishell.h"

t_envlist	*ft_lstnew(char *s)
{
	t_envlist	*new;
	char **out;

	out = ft_split(s, '=');
	new = (t_envlist *)malloc(sizeof(t_envlist));
	if (!(new))
		return (0);
	new->var_name = ft_strdup(out[0]);
	new->var_content = ft_strdup(out[1]);
	new->stock = s;
	new->next = NULL;
	free(out[0]);
	free(out[1]);
	free(out);
	return (new);
}

t_envlist	*ft_lstlast(t_envlist *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_envlist **lst, t_envlist *new)
{
	t_envlist	*last_node;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}
