/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:05:54 by syamada           #+#    #+#             */
/*   Updated: 2018/09/27 16:51:05 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**parse_dir(char **argv, char *curr)
{
}

void		cd_func(int argc, char **argv)
{
	char	*path;
	char	*curr;

	path = NULL;
	if (argc == 0 || ft_strequ(argv[0], "/"))
	{
		chdir("/");
		return ;
	}
	curr = get_envv("PWD");
	if (!*argv)
		path = get_envv("HOME");
	else
	{
	}
	update_envv("OLDPWD", curr);
	if (!chdir(path))
		update_envv("PWD", path);
	else
		ft_putstr_fd("No sush file or directory\n", 2);
}
