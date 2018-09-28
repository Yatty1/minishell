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

void	env_func(int argc, char **argv)
{
	int		i;

	i = 0;
	while (g_environ[i])
		ft_putendl(g_environ[i++]);
}

void	setenv_func(int argc, char **argv)
{
	if (argc != 2)
		return ;
	if (update_envv(argv[0], argv[1]))
		return ;
	new_envv(argv[0], argv[1]);
}

void	unsetenv_func(int argc, char **argv)
{
	if (argc != 1)
		return ;
	if (!get_envv(argv[0]))
		return ;
	del_envv(argv[0]);
}
