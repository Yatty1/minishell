/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 14:24:45 by syamada           #+#    #+#             */
/*   Updated: 2018/09/30 11:54:31 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_w(char *s, char c)
{
	int		i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			i++;
			while (*s != c && *s)
				s++;
		}
		if (*s)
			s++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(new = (char **)malloc(sizeof(char *) * (c_w((char *)s, c) + 1))))
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (!(new[j++] = ft_strsub((char *)s + i, 0,
						ft_strchr((char *)s + i, c) - (s + i))))
		{
			new[j] = 0;
			ft_tdstrdel(&new);
			return (NULL);
		}
		i += ft_strchr((char *)s + i, c) - ((char *)s + i);
		while (s[i] == c && s[i])
			i++;
	}
	new[j] = 0;
	return (new);
}
