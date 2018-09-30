/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:52:11 by syamada           #+#    #+#             */
/*   Updated: 2018/09/28 14:13:12 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parse_dollar(char *input, char *p)
{
	int		len;
	char	*pre;
	char	*new;
	char	*suf;

	len = 1;
	new = NULL;
	while (ft_isalpha(p[len]) && p[len])
		len++;
	if (!(pre = ft_strsub(input, 0, p - input)))
		pre = ft_strnew(1);
	if (!(suf = ft_strdup(input + (p - input + len))))
		suf = ft_strnew(1);
	p = ft_strsub(p, 1, len - 1);
	if (!(new = get_envv(p)))
		new = ft_strnew(1);
	new = ft_strjoinfree(pre, new);
	new = ft_strjoinfree(new, suf);
	ft_strdel(&p);
	ft_strdel(&input);
	return (new);
}

char	**parse_arg(char **argv)
{
	int		i;
	char	*new;

	i = 0;
	new = NULL;
	while (argv[i])
	{
		if (argv[i][0] == '~')
		{
			new = get_envv("HOME");
			new = ft_replace(argv[i], ft_charstr('~'), new);
			argv[i] = ft_strdup(new);
			ft_strdel(&new);
		}
		while ((new = ft_strchr(argv[i], '$')) && *new)
			argv[i] = parse_dollar(argv[i], new);
		i++;
	}
	return (argv);
}

void	read_cmd(void)
{
	char	*line;
	char	**input;
	char	*pwd;

	line = NULL;
	input = NULL;
	pwd = get_envv("PWD");
	ft_printf(" %s ", pwd);
	ft_putstr("$> ");
	ft_strdel(&pwd);
	while (get_next_line(0, &line) > 0)
	{
		input = ft_strsplit(line, ' ');
		input = parse_arg(input);
		dispatch_cmd(ft_tdstrnum(input), input);
		ft_tdstrdel(&input);
		ft_strdel(&line);
//		while (1);
		pwd = get_envv("PWD");
		ft_printf(" %s ", pwd);
		ft_strdel(&pwd);
		ft_putstr("$> ");
	}
}
