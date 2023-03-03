/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:27:28 by lnaidu            #+#    #+#             */
/*   Updated: 2023/03/03 14:59:54 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_data	prog;

	prog.i = (ac - 3);
	prog.j = 3;
	if (ac != 5)
		return (err("Error too many arguments"));
	prog.file1 = open (av[1], O_RDONLY);
	prog.file2 = open (av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 0666);
	if ((prog.file1 < 0) || (prog.file2 < 0))
		return (err("Error"));
	if (pipe(prog.fd) == -1)
		return (1);
	firstprocess(prog, av, env);
	while (prog.i > 2)
	{
		midprocess(prog, av, env, prog.j);
		prog.i--;
		prog.j++;
	}
	lastprocess(prog, av, env, ac);
	ft_close(prog);
	waitpid(prog.pid1, NULL, 0);
	return (0);
}
