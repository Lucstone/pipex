/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_herdoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:27:28 by lnaidu            #+#    #+#             */
/*   Updated: 2023/03/07 16:11:29 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_mainh(int ac, char **av, char **env)
{
	t_data	prog;

	prog.i = (ac - 4);
	prog.j = 4;
	prog.file1 = ft_openfile1(av, prog);
	prog.file2 = open (av[ac - 1], O_APPEND | O_CREAT | O_RDWR, 0666);
	if (prog.file1 < 0)
		return (ft_err(av[1]));
	if ((prog.file2 < 0))
		return (ft_err(av[ac - 2]));
	ft_firstprocesshd(prog, av, env);
	while (prog.i > 3)
	{
		ft_midprocess(prog, av, env, prog.j);
		prog.i--;
		prog.j++;
	}
	ft_lastprocess(prog, av, env, ac);
	ft_close(prog);
	waitpid(prog.pid1, NULL, 0);
	waitpid(prog.pidmid, NULL, 0);
	return (0);
}
