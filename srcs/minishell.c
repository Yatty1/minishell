/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 21:06:45 by syamada           #+#    #+#             */
/*   Updated: 2018/09/27 23:21:17 by syamada          ###   ########.fr       */
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

void   binary_cmd(char **argv)
{
	char		*bpath;
	char		path[PATH_MAX];
	char		**input;
	int		i;

	i = 0;
	bpath = get_envv("PATH");
	input = ft_strsplit(bpath, ':');
	ft_strdel(&bpath);
	while (input[i])
	{
		bpath = ft_strjoin_with(input[i], argv[0], '/');
		if (access(bpath, F_OK & X_OK) == 0)
			break;
		ft_strdel(&bpath);
		i++;
	}
	ft_tdstrdel(&input);
	ft_strcpy(path, bpath);
	ft_strdel(&bpath);
	execve(path, argv, g_environ);
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
	binary_cmd(argv);
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

/*
** IDEA:
** custom prompt with flag
*/

int		main(int argc, char **argv, char **env)
{
	pid_t	pid;

	init_environ(env);
	while (1)
	{
		pid = fork();
		if (pid != 0)
		{
			wait(&pid);
			if (WIFEXITED(pid) && WEXITSTATUS(pid) == 10)
				exit(1);
		}
		else if (!pid)
			read_cmd();
	}
	return (0);
}
