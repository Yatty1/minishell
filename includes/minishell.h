/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 21:06:06 by syamada           #+#    #+#             */
/*   Updated: 2018/10/02 19:44:02 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include <unistd.h>
# include <sys/wait.h>
# include <sys/syslimits.h>
# include <errno.h>

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
int				binary_cmd(char **argv);
void			read_cmd(void);

char			*get_envv(char *name);
int				update_envv(char *name, char *value);
void			new_envv(char *name, char *value);
void			del_envv(char *name);

char			*parse_dir(char *path, char *curr);

char			**remove_null(char **argv);
void			pwd_func(int argc, char **argv);
void			cd_func(int argc, char **argv);
void			echo_func(int argc, char **argv);
void			setenv_func(int argc, char **argv);
void			unsetenv_func(int argc, char **argv);
void			env_func(int argc, char **argv);
void			exit_func(int argc, char **argv);

void			error_exec(char *cmd, char *path, char *msg);
void			not_found(char *cmd);
void			error_binary(char *cmd);

#endif
