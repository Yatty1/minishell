/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:08:41 by syamada           #+#    #+#             */
/*   Updated: 2018/09/30 11:55:21 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_func(int argc, char **argv)
{
	int		num;

	if (argc == 0 && !*argv)
		num = 10;
	else if (argc == 1)
		num = ft_atoi(argv[0]);
	else
	{
		ft_putstrerr("Too many arguments");
		return ;
	}
	ft_tdstrdel(&g_environ);
	exit(num);
}
