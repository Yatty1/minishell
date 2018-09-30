#include "minishell.h"

void		error_exec(char *cmd, char *path, char *msg)
{
	char	*name;

	name = ft_strlast(path, '/');
	ft_putstrerr(cmd);
	ft_putstrerr(": ");
	if (path)
	{
		ft_putstrerr(name);
		ft_putstrerr(": ");
	}
	ft_putstrerr(msg);
	ft_strdel(&name);
}

void		not_found(char *cmd)
{
	struct stat	st;

	ft_putstrerr("bash: ");
	ft_putstrerr(cmd);
	ft_putstrerr(": ");
	if (*cmd != '/')
		ft_putstrerr("Command not found\n");
	else
	{
		lstat(cmd, &st);
		if (st.st_mode & S_IFDIR)
			ft_putstrerr("is a directory\n");
	}
	exit(1);
}
