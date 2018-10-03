/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 11:57:26 by syamada           #+#    #+#             */
/*   Updated: 2018/10/03 11:53:15 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		error_exec(char *cmd, char *path, char *msg)
{
	char	*name;

	name = ft_strlast(path, '/');
	ft_putstrerr(cmd);
	ft_putstrerr(": ");
	if (path)
	{
		ft_putstrerr(name);
		ft_putstrerr(": ");
	}
	ft_putstrerr(msg);
	ft_strdel(&name);
}

void		not_found(char *cmd)
{
	struct stat	st;

	ft_putstrerr("bash: ");
	ft_putstrerr(cmd);
	ft_putstrerr(": ");
	if (*cmd != '/' && !(cmd[0] == '.' && cmd[1] == '/'))
		ft_putstrerr("Command not found\n");
	else
	{
		lstat(cmd, &st);
		if (st.st_mode & S_IFDIR)
			ft_putstrerr("is a directory\n");
		else if (access(cmd, F_OK) == -1)
			ft_putstrerr("No such file or directory\n");
		else if (!(st.st_mode & S_IXUSR))
			ft_putstrerr("Permission denied\n");
	}
	exit(1);
}
