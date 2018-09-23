/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 21:06:45 by syamada           #+#    #+#             */
/*   Updated: 2018/09/23 16:32:06 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini.h"

t_cmd	g_cmd_table[CMD_NUM] = {
	{"pwd", &pwd_func},
	{"cd", &cd_func},
	{"echo", &echo_func},
	{"setenv", &setenv_func},
	{"unsetenv", &unsetenv_func},
	{"env", &env_func},
	{"exit", &exit_func},
};

void	dispatch_cmd(int argc, char	**argv)
{
	int		i;

	i = 0;
	while (i < CMD_NUM)
	{
		if (ft_strequ(argv[0], g_cmd_table[i].name))
		{
			g_cmd_table[i].func(--argc, ++argv);
			return ;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	char	*line;
	char *const c[] = {"/bin/ls", "-l", ".", 0};

	line = NULL;
	execve(c[0], c, NULL);
	/*
	ft_putstr("$> ");
	while (get_next_line(0, &line) > 0)
	{
		ft_putendl(line);
		ft_strdel(&line);
		ft_putstr("$> ");
	}
	*/
	return (0);
}
