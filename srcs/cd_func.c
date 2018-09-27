/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:05:54 by syamada           #+#    #+#             */
/*   Updated: 2018/09/26 23:15:51 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_func(int argc, char **argv)
{
	char	*path;
	char	*curr;

	path = NULL;
	curr = get_envv("PWD");
	if (!*argv)
		path = get_envv("HOME");
	else
	{
	}
	update_envv("OLDPWD", curr);
	if (!chdir(path))
		update_envv("PWD", path);
}
