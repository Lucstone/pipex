/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:13:26 by lnaidu            #+#    #+#             */
/*   Updated: 2023/03/08 18:51:09 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_freesplit(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}

void	ft_close(t_data prog)
{
	close(prog.fd[0]);
	close(prog.fd[1]);
}

int	ft_openfile(char **av, t_data prog)
{
	prog.file1 = open (av[1], O_DIRECTORY);
	if (prog.file1 != -1)
	{
		write(2, "Not a file it's a directory\n", 28);
		return (-1);
	}
	else
	{
		prog.file1 = open (av[1], O_RDONLY);
	}
	return (prog.file1);
}

int	ft_open(char **av)
{
	int	file11;

	file11 = open (av[1], O_DIRECTORY);
	if (file11 != -1)
	{
		write(2, "Not a file it's a directory\n", 28);
		return (-1);
	}
	else
	{
		file11 = open (av[1], O_RDONLY);
	}
	return (file11);
}
