#include "minishell.h"

char	*strjoin_free(char *s1, char *s2)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (ret);
}
