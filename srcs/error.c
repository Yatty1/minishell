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

void		not_found(void)
{
	ft_putstrerr("bash: Command not found\n");
}
