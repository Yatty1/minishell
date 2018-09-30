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
	if (argv[0][0] == '/')
		path = ft_strequ(argv[0], "/") ? ft_strdup("/") : ft_strdup(argv[0]);
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
