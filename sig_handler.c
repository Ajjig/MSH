#include "minishell.h"

void cltr_c(int sig)
{
	printf("\n");
	g_variable.g_exites = 128 + sig;
	if (!g_variable.is_running)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

int signal_handler()
{
	signal(SIGINT, &cltr_c);
	signal(SIGQUIT, SIG_IGN);
	return 0;
}

