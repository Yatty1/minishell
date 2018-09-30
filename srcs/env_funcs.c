/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:13:21 by syamada           #+#    #+#             */
/*   Updated: 2018/09/27 22:44:47 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	env_usage(char *cmd)
{
	if (ft_strequ(cmd, "setenv"))
		ft_putstrerr("Usage: setenv <<key, value>, ...>\n");
	else if (ft_strequ(cmd, "unsetenv"))
		ft_putstrerr("Usage: unsetenv <key>\n");
	else if (ft_strequ(cmd, "env"))
		ft_putstrerr("env: Too many arguments\n");
}

void		env_func(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc > 0)
		return (env_usage("env"));
	while (g_environ[i])
		ft_putendl(g_environ[i++]);
}

void		setenv_func(int argc, char **argv)
{
	if (argc != 2)
		return (env_usage("unsetenv"));
	if (update_envv(argv[0], argv[1]))
		return ;
	new_envv(argv[0], argv[1]);
}

void		unsetenv_func(int argc, char **argv)
{
	int		i;
	char	*envv;

	i = 0;
	if (argc < 1)
		return (env_usage("unsetenv"));
	while (argv[i])
	{
		if (!(envv = get_envv(argv[i])))
		{
			ft_strdel(&envv);
			continue;
		}
		ft_strdel(&envv);
		del_envv(argv[i]);
		i++;
	}
}
