/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:06:37 by syamada           #+#    #+#             */
/*   Updated: 2018/10/06 22:31:51 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd_func(int argc, char **argv)
{
	char	*pwd;

	pwd = (char *)malloc(sizeof(char) * PATH_MAX);
	getcwd(pwd, PATH_MAX);
	ft_putendl(pwd);
	ft_strdel(&pwd);
}
