/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:52:11 by syamada           #+#    #+#             */
/*   Updated: 2018/10/13 14:45:26 by syamada          ###   ########.fr       */
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
	while ((ft_isalnum(p[len]) || p[len] == '_') && p[len])
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
	int		j;

	len = 0;
	i = -1;
	j = 0;
	while (argv[++i])
		len += argv[i][0] != '\0' ? 1 : 0;
	av = (char **)malloc(sizeof(char *) * (len + 1));
	i = -1;
	while (argv[++i])
	{
		if (argv[i][0] != '\0')
			av[j++] = ft_strdup(argv[i]);
	}
	av[j] = 0;
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
			if ((argv[i] = parse_dollar(argv[i], new)) &&
					ft_strequ(argv[i], new))
				break ;
		i++;
	}
	return (remove_null(argv));
}

void	read_cmd(void)
{
	char	*line;
	char	**input;
	char	**commands;
	char	*pwd;
	int		i;

	line = NULL;
	print_prompt();
	while (get_next_line(0, &line) > 0)
	{
		commands = ft_strsplit(line, ';');
		i = -1;
		while (commands[++i])
		{
			commands[i] = replace_char(commands[i], '\t', ' ');
			input = ft_strsplit(commands[i], ' ');
			input = parse_arg(input);
			dispatch_cmd(ft_tdstrnum(input), input);
			ft_tdstrdel(&input);
		}
		ft_tdstrdel(&commands);
		ft_strdel(&line);
		print_prompt();
	}
}
