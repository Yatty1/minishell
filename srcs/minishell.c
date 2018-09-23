/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 21:06:45 by syamada           #+#    #+#             */
/*   Updated: 2018/09/22 23:24:16 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini.h"

int		main(int argc, char **argv)
{
	char	*line;

	line = NULL;
	ft_putstr("$> ");
	while (get_next_line(0, &line) > 0)
	{
		ft_putendl(line);
		ft_strdel(&line);
		ft_putstr("$> ");
	}
	return (0);
}
