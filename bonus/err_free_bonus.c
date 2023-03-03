/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_free_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:13:26 by lnaidu            #+#    #+#             */
/*   Updated: 2023/03/03 14:44:50 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	freesplit(char **tab)
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

int	err(char *str)
{
	perror(str);
	return (12);
}

void	ft_close(t_data prog)
{
	close(prog.fd[0]);
	close(prog.fd[1]);
}
