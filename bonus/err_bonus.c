/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:13:26 by lnaidu            #+#    #+#             */
/*   Updated: 2023/03/08 17:49:45 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_err(char *str)
{
	perror(str);
	exit (1);
}

int	ft_err2(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	return (12);
}

int	ft_errexcev(char *str)
{
	write(2, str, ft_strlen (str));
	write(2, ": command not found\n", 28);
	exit (1);
}

int	ft_open(char **av)
{
	int	file11;

	file11 = open (av[1], O_DIRECTORY);
	if (file11 != -1)
		return (-1);
	else
		file11 = open (av[1], O_RDONLY);
	return (file11);
}
