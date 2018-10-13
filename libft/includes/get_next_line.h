/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 12:34:17 by syamada           #+#    #+#             */
/*   Updated: 2018/10/13 13:51:24 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1024
# define FDN 4864
# include "libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

int		get_next_line(const int fd, char **line);

#endif
