/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <iidkhebb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:02:53 by iidkhebb          #+#    #+#             */
/*   Updated: 2022/03/25 01:03:10 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cltr_c(int sig)
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

int	signal_handler(void)
{
	signal(SIGINT, &cltr_c);
	signal(SIGQUIT, SIG_IGN);
	return (0);
}
