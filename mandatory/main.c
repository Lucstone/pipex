/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:27:28 by lnaidu            #+#    #+#             */
/*   Updated: 2023/03/08 20:05:42 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_mainfileok(int ac, char **av, char **env)
{
	t_data	prog;

	prog.i = (ac - 3);
	prog.j = 3;
	if (ac != 5)
		return (ft_err2("Error not good number of arguments\n", 1));
	prog.file1 = ft_openfile(av, prog);
	prog.file2 = open (av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 0666);
	if (prog.file1 < 0)
		return (ft_err(av[1]));
	if ((prog.file2 < 0))
		return (ft_err(av[ac - 2]));
	ft_firstprocess(prog, av, env);
	while (prog.i > 2)
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

int	ft_mainfilenotok(int ac, char **av, char **env)
{
	t_data	prog;

	perror (av[1]);
	prog.i = (ac - 3);
	prog.j = 3;
	if (ac != 5)
		return (ft_err2("Error not good number of arguments\n", 1));
	prog.file1 = open(".filetmp", O_TRUNC | O_CREAT | O_RDWR, 0666);
	unlink(".filetmp");
	prog.file2 = open (av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 0666);
	if ((prog.file2 < 0))
		return (ft_err(av[ac - 2]));
	ft_firstprocess1(prog, av, env);
	while (prog.i > 1)
	{
		ft_midprocess(prog, av, env, prog.j);
		prog.i--;
		prog.j++;
	}
	ft_lastprocess(prog, av, env, ac);
	waitpid(prog.pid1, NULL, 0);
	waitpid(prog.pidmid, NULL, 0);
	ft_close(prog);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	int	fd;

	if (ac != 5)
		return (ft_err2("Error not good number of arguments\n", 1));
	fd = ft_open(av);
	if (fd < 0)
		ft_mainfilenotok(ac, av, env);
	else
		ft_mainfileok(ac, av, env);
	return (0);
}
