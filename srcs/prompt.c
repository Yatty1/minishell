/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:41:47 by syamada           #+#    #+#             */
/*   Updated: 2018/10/06 12:46:16 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_prompt(void)
{
	char	*pwd;
	char	*usr;

	if (!(usr = get_envv("USER")))
		usr = ft_strnew(1);
	if (!(pwd = get_envv("PWD")))
	{
		pwd = (char *)malloc(sizeof(char) * PATH_MAX);
		pwd = getcwd(pwd, PATH_MAX);
	}
	pwd = ft_replace(pwd, get_envv("HOME"), ft_charstr('~'));
	ft_printf("\e[1;34m%s\e[1;37m:\n\e[1;31m%s \e[1;37m$ \e[0m", pwd, usr);
	ft_strdel(&usr);
	ft_strdel(&pwd);
}
