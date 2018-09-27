/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:07:51 by syamada           #+#    #+#             */
/*   Updated: 2018/09/26 23:04:36 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		update_envv(char *name, char *value)
{
	int		i;
	char	*str;

	i = 0;
	while (g_environ[i])
	{
		str = ft_strsub(g_environ[i], 0, ft_strchr(g_environ[i], '=') - g_environ[i]);
		if (ft_strequ(name, str))
		{
			ft_strdel(&str);
			ft_strdel(&g_environ[i]);
			g_environ[i] = ft_strjoin_with(name, value, '=');
			return (1);
		}
		ft_strdel(&str);
		i++;
	}
	return (0);
}

void	new_envv(char *name, char *value)
{
	int		len;
	int		i;
	char	**tmp;

	i = 0;
	len = ft_tdstrnum(g_environ);
	tmp = (char **)ft_memalloc(sizeof(char *) * (len + 2));
	while (i < len - 1)
	{
		tmp[i] = ft_strdup(g_environ[i]);
		i++;
	}
	tmp[i] = ft_strjoin_with(name, value, '=');
	tmp[i + 1] = ft_strdup(g_environ[i]);
	tmp[i + 2] = 0;
	ft_tdstrdel(&g_environ);
	g_environ = (char **)ft_memalloc(sizeof(char *) * (len + 2));
	i = -1;
	while (tmp[++i])
		g_environ[i] = ft_strdup(tmp[i]);
	g_environ[i] = 0;
	ft_tdstrdel(&tmp);
}

void	setenv_func(int argc, char **argv)
{
	if (argc != 2)
		return ;
	if (update_envv(argv[0], argv[1]))
		return ;
	new_envv(argv[0], argv[1]);
}
