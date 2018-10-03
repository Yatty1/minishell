/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:05:54 by syamada           #+#    #+#             */
/*   Updated: 2018/10/03 12:08:30 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ch_dir(char *path, char *curr)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * PATH_MAX);
	if (!update_envv("OLDPWD", curr ? curr : getcwd(new, PATH_MAX)))
		new_envv("OLDPWD", curr ? curr : getcwd(new, PATH_MAX));
	ft_memset(new, '\0', ft_strlen(new));
	if (!chdir(path))
	{
		if (!update_envv("PWD", getcwd(new, PATH_MAX)))
			new_envv("PWD", getcwd(new, PATH_MAX));
	}
	ft_strdel(&new);
}

char		*check_access(char *path)
{
	struct stat	st;
	struct stat nst;

	if (!path)
		return (NULL);
	lstat(path, &st);
	stat(path, &nst);
	if (access(path, F_OK) == -1)
		return ("No such file or directory\n");
	if ((!(nst.st_mode & S_IFDIR) && !(st.st_mode & S_IFLNK)) ||
			((st.st_mode & S_IFLNK) && (nst.st_mode & S_IFREG)))
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
	if (*argv && argv[0][0] == '/')
		path = ft_strequ(argv[0], "/") ? ft_strdup("/") : ft_strdup(argv[0]);
	else if (ft_strequ(argv[0], "-"))
		path = get_envv("OLDPWD");
	else if (!*argv)
		path = get_envv("HOME");
	else
		path = ft_strdup(argv[0]);
	if ((emsg = check_access(path)))
		error_exec("cd", path, emsg);
	else
		ch_dir(path, curr);
	ft_strdel(&path);
	ft_strdel(&curr);
}
