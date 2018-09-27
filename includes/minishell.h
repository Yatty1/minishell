/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 21:06:06 by syamada           #+#    #+#             */
/*   Updated: 2018/09/26 22:40:42 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include <unistd.h>

# define CMD_NUM 7

char			**g_environ;

typedef	void	(t_cmdfunc)(int, char **);

typedef struct	s_cmd
{
	char		*name;
	t_cmdfunc	*func;
}				t_cmd;

void			init_environ(char **env);
void			dispatch_cmd(int argc, char **argv);
char			*get_envv(char *name);

void			pwd_func(int argc, char **argv);
void			cd_func(int argc, char **argv);
void			echo_func(int argc, char **argv);
void			setenv_func(int argc, char **argv);
void			unsetenv_func(int argc, char **argv);
void			env_func(int argc, char **argv);
void			exit_func(int argc, char **argv);
#endif
