/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:13:26 by lnaidu            #+#    #+#             */
/*   Updated: 2023/03/07 16:13:43 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_err(char *str)
{
	perror(str);
	exit(1);
}

int	ft_err2(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	return (1);
}

int	ft_errexcev(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, ": command not found\n", 28);
	exit (1);
}
