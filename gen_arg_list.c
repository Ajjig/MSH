#include "minishell.h"

t_arglist	*new_arg(char *arg)
{
	t_arglist	*new;

	new = (t_arglist *) malloc (sizeof(t_arglist));
	new -> arg = ft_strdup(arg);
	new -> next = NULL;
	return (new);
}

t_arglist	*gen_arg_list(char *args)
{
	t_arglist	*list;
	int			i;
	char		*next;
	t_arglist	*bak;

	i = 0;
	if (args == NULL)
		return (NULL);
	next = __next__(&args[i]);
	i += ft_strlen(next);
	list = new_arg(next);
	bak = list;
	free(next);
	while (args[i])
	{
		next = __next__(&args[i]);
		i += ft_strlen(next) + 1;
		list -> next = new_arg(next);
		list = list -> next;
		free(next);
	}
	return (bak);
}
