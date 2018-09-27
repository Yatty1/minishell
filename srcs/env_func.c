/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:13:21 by syamada           #+#    #+#             */
/*   Updated: 2018/09/26 23:04:40 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_envv(char *name)
{
	int		i;
	char	*p;
	char	*str;

	i = 0;
	while(g_environ[i])
	{
		p = ft_strchr(g_environ[i], '=');
		str = ft_strsub(g_environ[i], 0, p - g_environ[i]);
		if (ft_strequ(name, str))
		{
			ft_strdel(&str);
			return (ft_strdup(p + 1));
		}
		ft_strdel(&str);
		i++;
	}
	return (NULL);
}

void	env_func(int argc, char **argv)
{
	int		i;

	i = 0;
	while (g_environ[i])
		ft_putendl(g_environ[i++]);
}
