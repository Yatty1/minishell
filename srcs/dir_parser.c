/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 11:57:31 by syamada           #+#    #+#             */
/*   Updated: 2018/09/30 11:57:33 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**tdstrsub(char **tdstr, int start, int len)
{
	char	**new;
	int		i;

	i = 0;
	new = (char **)malloc(sizeof(char *) * (len - start + 1));
	while (len--)
		new[i++] = ft_strdup(tdstr[start++]);
	new[i] = 0;
	ft_tdstrdel(&tdstr);
	return (new);
}

static char	**tdstrappend(char **tdstr, char *new)
{
	int		i;
	char	**newtd;

	i = ft_tdstrnum(tdstr);
	newtd = (char **)malloc(sizeof(char *) * (i + 2));
	i = -1;
	while (tdstr[++i])
		newtd[i] = ft_strdup(tdstr[i]);
	newtd[i] = ft_strdup(new);
	newtd[i + 1] = 0;
	ft_tdstrdel(&tdstr);
	return (newtd);
}

char		*parse_dir(char *path, char *curr)
{
	char	**dpath;
	char	**cpath;
	int		i;

	i = -1;
	dpath = ft_strsplit(path, '/');
	cpath = ft_strsplit(curr, '/');
	ft_strdel(&path);
	while (dpath[++i])
		if (ft_strequ(dpath[i], ".."))
			cpath = tdstrsub(cpath, 0, ft_tdstrnum(cpath) - 1);
		else if (ft_strequ(dpath[i], "."))
			continue ;
		else
			cpath = tdstrappend(cpath, dpath[i]);
	i = 0;
	path = ft_strnew(1);
	while (cpath[i])
		path = ft_strjoinfree_with(path, ft_strdup(cpath[i++]), '/');
	ft_tdstrdel(&cpath);
	ft_tdstrdel(&dpath);
	return (path);
}
