/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:07:51 by syamada           #+#    #+#             */
/*   Updated: 2018/09/27 15:06:06 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setenv_func(int argc, char **argv)
{
	if (argc != 2)
		return ;
	if (update_envv(argv[0], argv[1]))
		return ;
	new_envv(argv[0], argv[1]);
}
