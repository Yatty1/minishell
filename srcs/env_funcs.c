/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:13:21 by syamada           #+#    #+#             */
/*   Updated: 2018/10/13 14:41:31 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	env_usage(char *cmd)
{
	if (ft_strequ(cmd, "setenv"))
		ft_putstrerr("Usage: setenv <key=value>\n");
	else if (ft_strequ(cmd, "unsetenv"))
		ft_putstrerr("Usage: unsetenv <key>\n");
	else if (ft_strequ(cmd, "env"))
		ft_putstrerr("env: Too many arguments\n");
}

static void	illegal_literal(char *name, char *av)
{
	ft_putstrerr("bash: ");
	ft_putstrerr(av);
	ft_putstrerr(" : invalid indentifier\n");
	ft_strdel(&name);
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
	char	*name;
	char	*value;
	char	*p;
	int		i;

	i = -1;
	if (argc != 1)
		return (env_usage("setenv"));
	if (!(p = ft_strchr(argv[0], '=')))
		return ;
	if (!(name = ft_strsub(argv[0], 0, p - argv[0])))
		return (env_usage("setenv"));
	while (name[++i])
		if (!(ft_isalnum(name[i]) || name[i] == '_'))
			return (illegal_literal(name, argv[0]));
	if (!(value = ft_strdup(argv[0] + (p - argv[0] + 1))))
		return (env_usage("setenv"));
	if (!update_envv(name, value))
		new_envv(name, value);
	ft_strdel(&name);
	ft_strdel(&value);
}

void		unsetenv_func(int argc, char **argv)
{
	int		i;
	char	*envv;

	i = -1;
	if (argc < 1)
		return (env_usage("unsetenv"));
	while (argv[++i])
	{
		if (!(envv = get_envv(argv[i])))
		{
			ft_strdel(&envv);
			continue;
		}
		ft_strdel(&envv);
		del_envv(argv[i]);
	}
}
