/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:08:17 by syamada           #+#    #+#             */
/*   Updated: 2018/09/26 23:04:28 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_envv(char *name)
{
	int		i;
	int		j;
	char	*str;
	char	**tmp;

	i = 0;
	j = ft_tdstrnum(g_environ);
	tmp = (char **)ft_memalloc(sizeof(char *) * j);
	j = 0;
	while (g_environ[i])
	{
		str = ft_strsub(g_environ[i], 0, ft_strchr(g_environ[i], '=') - g_environ[i]);
		if (!ft_strequ(name, str))
			tmp[j++] = ft_strdup(g_environ[i]);
		i++;
	}
	tmp[j] = 0;
	ft_tdstrdel(&g_environ);
	g_environ = (char **)ft_memalloc(sizeof(char *) * (j + 1));
	j = -1;
	while (tmp[++j])
		g_environ[j] = ft_strdup(tmp[j]);
	g_environ[j] = 0;
	ft_tdstrdel(&tmp);
}

void	unsetenv_func(int argc, char **argv)
{
	if (argc != 1)
		return ;
	if (!get_envv(argv[0]))
		return ;
	del_envv(argv[0]);
}
