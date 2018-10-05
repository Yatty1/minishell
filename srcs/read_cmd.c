/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:52:11 by syamada           #+#    #+#             */
/*   Updated: 2018/10/04 15:31:37 by syamada          ###   ########.fr       */
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
	if (len == 1)
		return (input);
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

char	**remove_null(char **argv)
{
	char	**av;
	int		len;
	int		i;

	len = 0;
	i = -1;
	while (argv[++i])
		len += argv[i][0] ? 1 : 0;
	av = (char **)malloc(sizeof(char *) * (len + 1));
	i = -1;
	while (argv[++i])
		av[i] = ft_strdup(argv[argv[i][0] != '\0' ? i : i + 1]);
	av[i] = 0;
	ft_tdstrdel(&argv);
	return (av);
}

char	*replace_char(char *str, char c, char r)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			str[i] = r;
		i++;
	}
	return (str);
}

char	**parse_arg(char **argv)
{
	int		i;
	char	*new;

	i = 0;
	new = NULL;
	while (argv[i])
	{
		if (argv[i][0] == '~' && (argv[i][1] == '/' || argv[i][1] == '\0'))
		{
			if (!(new = get_envv("HOME")))
				new = ft_strnew(1);
			new = ft_replace(argv[i], ft_charstr('~'), new);
			argv[i] = ft_strdup(new);
			ft_strdel(&new);
		}
		while ((new = ft_strchr(argv[i], '$')) && *new)
			if ((argv[i] = parse_dollar(argv[i], new)) && ft_strequ(argv[i], new))
				break ;
		i++;
	}
	return (remove_null(argv));
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
		line = replace_char(line, '\t', ' ');
		input = ft_strsplit(line, ' ');
		input = parse_arg(input);
		dispatch_cmd(ft_tdstrnum(input), input);
		ft_tdstrdel(&input);
		ft_strdel(&line);
		pwd = get_envv("PWD");
		ft_printf(" %s ", pwd);
		ft_strdel(&pwd);
		ft_putstr("$> ");
	}
}
