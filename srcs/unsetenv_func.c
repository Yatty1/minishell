/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:08:17 by syamada           #+#    #+#             */
/*   Updated: 2018/09/27 15:06:24 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unsetenv_func(int argc, char **argv)
{
	if (argc != 1)
		return ;
	if (!get_envv(argv[0]))
		return ;
	del_envv(argv[0]);
}
