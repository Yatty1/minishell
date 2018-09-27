/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:13:21 by syamada           #+#    #+#             */
/*   Updated: 2018/09/27 15:05:40 by syamada          ###   ########.fr       */
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
