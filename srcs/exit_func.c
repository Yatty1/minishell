/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:08:41 by syamada           #+#    #+#             */
/*   Updated: 2018/09/28 14:35:00 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// can specify exit number

void	exit_func(int argc, char **argv)
{
	if (argc == 0 && !*argv)
	{
		ft_tdstrdel(&g_environ);
		exit(10);
	}
}
