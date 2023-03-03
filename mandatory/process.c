/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:33:57 by lnaidu            #+#    #+#             */
/*   Updated: 2023/03/03 14:40:16 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	firstprocess(t_data proc, char **av, char **env)
{
	dup2(proc.file1, 0);
	dup2(proc.file2, 1);
	pipe(proc.fd);
	proc.pid1 = fork();
	if (proc.pid1 < 0)
		exit(EXIT_FAILURE);
	if (proc.pid1)
	{
		close(proc.fd[1]);
		dup2(proc.fd[0], STDIN_FILENO);
	}
	else
	{
		close(proc.fd[0]);
		dup2(proc.fd[1], 1);
		proc.tab = ft_split(av[2], ' ');
		proc.path = get_cmdpath(env, *proc.tab);
		if (execve(proc.path, &proc.tab[0], env) == -1)
		{
			err("execve");
			freesplit (proc.tab);
			return ;
		}
	}
}

void	midprocess(t_data proc, char **av, char **env, int j)
{
	pipe(proc.fd);
	proc.pidmid = fork();
	if (proc.pidmid < 0)
		exit(EXIT_FAILURE);
	if (proc.pidmid)
	{
		close(proc.fd[1]);
		dup2(proc.fd[0], STDIN_FILENO);
		waitpid(proc.pidmid, NULL, 0);
	}
	else
	{
		close(proc.fd[0]);
		dup2(proc.fd[1], 1);
		proc.tab = ft_split(av[j], ' ');
		proc.path = get_cmdpath(env, *proc.tab);
		if (execve(proc.path, &proc.tab[0], env) == -1)
		{
			err("execve");
			freesplit (proc.tab);
			return ;
		}
	}
}

void	lastprocess(t_data proc, char **av, char **env, int ac)
{
	proc.tab = ft_split(av[ac - 2], ' ');
	proc.path = get_cmdpath(env, *proc.tab);
	if (execve(proc.path, &proc.tab[0], env) == -1)
	{
		err("execve");
		freesplit (proc.tab);
		return ;
	}
}
