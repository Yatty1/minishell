/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 15:24:06 by syamada           #+#    #+#             */
/*   Updated: 2018/10/06 12:46:14 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_replace(char *str, char *target, char *rep)
{
	char	*p;
	char	*pre;
	char	*suf;
	char	*new;

	if (!target || !(p = ft_strstr(str, target)))
	{
		ft_strdel(&rep);
		ft_strdel(&target);
		return (str);
	}
	pre = p - str == 0 ? ft_strnew(1) : ft_strsub(str, 0, p - str);
	suf = ft_strdup(str + (p - str + ft_strlen(target)));
	new = ft_strjoinfree(pre, rep);
	new = ft_strjoinfree(new, suf);
	ft_strdel(&str);
	ft_strdel(&target);
	return (new);
}
