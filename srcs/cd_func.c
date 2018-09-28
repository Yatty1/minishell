/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:05:54 by syamada           #+#    #+#             */
/*   Updated: 2018/09/27 23:18:04 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*parse_dir(char *path, char *curr)
{
	char	**dpath;
	char	**cpath;
	char	**newpath;
	int		len;
	int		c;
	int		i;

	i = -1;
	c = 0;
	dpath = ft_strsplit(path, '/');
	cpath = ft_strsplit(curr, '/');
	ft_strdel(&path);
	while (dpath[++i])
	{
		if (ft_strequ("..", dpath[i]))
			c++;
	}
	i = 0;
	len = ft_tdstrnum(cpath);
	path = ft_strnew(1);
	while (i < len - c)
		path = ft_strjoin_with(path, cpath[i++], '/');
	i = 0;
	while (dpath[i])
	{
		if (!ft_strequ(dpath[i], ".") && !ft_strequ(dpath[i], ".."))
			path = ft_strjoin_with(path, dpath[i], '/');
		i++;
	}
	ft_putstr("path:");
	ft_putendl(path);
	return (path);
}

void		ch_dir(char *path, char *curr)
{
	update_envv("OLDPWD", curr);
	if (!chdir(path))
		update_envv("PWD", path);
	else
		ft_putstr_fd("No sush file or directory\n", 2);
}

void		cd_func(int argc, char **argv)
{
	char	*path;
	char	*curr;

	path = NULL;
	curr = get_envv("PWD");
	if (ft_strequ(argv[0], "/"))
		path = ft_strdup("/");
	else if (!*argv)
		path = get_envv("HOME");
	else
		path = parse_dir(ft_strdup(argv[0]), curr);
	ch_dir(path, curr);
}
