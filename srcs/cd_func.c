/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:05:54 by syamada           #+#    #+#             */
/*   Updated: 2018/09/28 14:34:16 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//need implementation for - arguemnt which let you go to oldpwd

static int	count_parent(char **dpath)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (dpath[++i])
		if (ft_strequ("..", dpath[i]))
			count++;
	return (count);
}

static char	*parse_dir(char *path, char *curr)
{
	char	**dpath;
	char	**cpath;
	char	*tmp;
	int		len;
	int		c;
	int		i;

	dpath = ft_strsplit(path, '/');
	cpath = ft_strsplit(curr, '/');
	c = count_parent(dpath);
	i = 0;
	len = ft_tdstrnum(cpath);
	path = ft_strnew(1);
	while (i < len - c)
	{
		tmp = ft_strjoin_with(path, cpath[i++], '/');
		ft_strdel(&path);
		path = tmp;
	}
	i = -1;
	while (dpath[++i])
	{
		if (!ft_strequ(dpath[i], ".") && !ft_strequ(dpath[i], ".."))
		{
			tmp = ft_strjoin_with(path, dpath[i], '/');
			ft_strdel(&path);
			path = tmp;
		}
	}
	ft_tdstrdel(&dpath);
	ft_tdstrdel(&cpath);
	return (path);
}

void		ch_dir(char *path, char *curr)
{
	update_envv("OLDPWD", curr);
	if (!chdir(path))
		update_envv("PWD", path);
}

char		*check_access(char *path)
{
	struct stat	st;

	lstat(path, &st);
	if (access(path, F_OK) == -1)
		return ("No such file or directory\n");
	if (!(st.st_mode & S_IFDIR))
		return ("Not a directory\n");
	if (!(st.st_mode & S_IXUSR))
		return ("Permission denied\n");
	return (NULL);
}

void		cd_func(int argc, char **argv)
{
	char	*path;
	char	*curr;
	char	*emsg;

	path = NULL;
	emsg = NULL;
	curr = get_envv("PWD");
	if (ft_strequ(argv[0], "/"))
		path = ft_strdup("/");
	else if (ft_strequ(argv[0], "-"))
		path = get_envv("OLDPWD");
	else if (!*argv)
		path = get_envv("HOME");
	else
		path = parse_dir(ft_strdup(argv[0]), curr);
	if ((emsg = check_access(path)))
		error_exec("cd", path, emsg);
	else
		ch_dir(path, curr);
	ft_strdel(&path);
	ft_strdel(&curr);
}
