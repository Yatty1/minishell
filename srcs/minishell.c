/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 21:06:45 by syamada           #+#    #+#             */
/*   Updated: 2018/09/26 23:15:52 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	g_cmd_table[CMD_NUM] = {
	{"pwd", &pwd_func},
	{"cd", &cd_func},
	{"echo", &echo_func},
	{"setenv", &setenv_func},
	{"unsetenv", &unsetenv_func},
	{"env", &env_func},
	{"exit", &exit_func},
};

void	path_cmd(char **argv)
{
	char *cmd;

	cmd = ft_strjoin("/bin/", argv[0]);
	execve(cmd, argv, g_environ);
	ft_strdel(&cmd);
}

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
	path_cmd(argv);
}

void	init_environ(char **env)
{
	int		i;

	i = ft_tdstrnum(env);
	g_environ = (char **)ft_memalloc(sizeof(char *) * (i + 1));
	i = -1;
	while (env[++i])
		g_environ[i] = ft_strdup(env[i]);
	g_environ[i] = 0;
}

int		main(int argc, char **argv, char **env)
{
	char	*line;
	char	**input;

	line = NULL;
	init_environ(env);
	ft_putstr("$> ");
	while (get_next_line(0, &line) > 0)
	{
		input = ft_strsplit(line, ' ');
		dispatch_cmd(ft_tdstrnum(input), input);
		ft_tdstrdel(&input);
		ft_strdel(&line);
		ft_putstr("$> ");
	}
	return (0);
}
