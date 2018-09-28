/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:52:11 by syamada           #+#    #+#             */
/*   Updated: 2018/09/27 22:15:26 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char	**parse_arg(char **argv)
{
	int		i;
	char	*new;

	i = 0;
	new = NULL;
	while (argv[i])
	{
		if (argv[i][0] == '$')
		{
			new = get_envv(argv[i] + 1);
			argv[i] = new;
		}
		else if (argv[i][0] == '~')
		{
			new = get_envv("HOME");
			new = ft_replace(argv[i], ft_charstr('~'), new);
			argv[i] = new;
		}
		i++;
	}
	return (argv);
}

void	read_cmd(void)
{
	char	*line;
	char	**input;

	line = NULL;
	input = NULL;
	ft_putstr("$> ");
	while (get_next_line(0, &line) > 0)
	{
		input = ft_strsplit(line, ' ');
		input = parse_arg(input);
		dispatch_cmd(ft_tdstrnum(input), input);
		ft_tdstrdel(&input);
		ft_strdel(&line);
		ft_putstr("$> ");
	}
}
