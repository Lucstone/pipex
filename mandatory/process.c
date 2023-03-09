/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:33:57 by lnaidu            #+#    #+#             */
/*   Updated: 2023/03/09 11:09:12 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_firstprocess(t_data proc, char **av, char **env)
{
	pipe(proc.fd);
	proc.pid1 = fork();
	if (proc.pid1 < 0)
		exit(EXIT_FAILURE);
	if (proc.pid1)
	{
		close(proc.fd[1]);
		dup2(proc.fd[0], STDIN_FILENO);
		close(proc.fd[0]);
	}
	else
	{
		dup2(proc.file1, 0);
		close(proc.fd[0]);
		dup2(proc.fd[1], 1);
		close(proc.fd[1]);
		proc.tab = ft_split(av[2], ' ');
		proc.path = ft_get_cmdpath(env, *proc.tab);
		if (execve(proc.path, &proc.tab[0], env) == -1)
		{
			ft_freesplit (proc.tab);
			ft_errexcev(av[2]);
			exit (EXIT_FAILURE);
		}
	}
}

void	ft_firstprocess1(t_data proc, char **av, char **env)
{
	av[2] = "cat";
	pipe(proc.fd);
	proc.pid1 = fork();
	if (proc.pid1 < 0)
		exit(EXIT_FAILURE);
	if (proc.pid1)
	{
		close(proc.fd[1]);
		dup2(proc.fd[0], STDIN_FILENO);
		close(proc.fd[0]);
	}
	else
	{
		dup2(proc.file1, 0);
		close(proc.fd[0]);
		dup2(proc.fd[1], 1);
		close(proc.fd[1]);
		proc.tab = ft_split(av[2], ' ');
		proc.path = ft_get_cmdpath(env, *proc.tab);
		if (execve(proc.path, &proc.tab[0], env) == -1)
		{
			ft_freesplit (proc.tab);
			exit (EXIT_FAILURE);
		}
	}
}

void	ft_midprocess(t_data proc, char **av, char **env, int j)
{
	pipe(proc.fd);
	proc.pidmid = fork();
	if (proc.pidmid < 0)
		exit(EXIT_FAILURE);
	if (proc.pidmid)
	{
		close(proc.fd[1]);
		dup2(proc.fd[0], STDIN_FILENO);
		close(proc.fd[0]);
		waitpid(proc.pidmid, NULL, 0);
	}
	else
	{
		close(proc.fd[0]);
		dup2(proc.fd[1], 1);
		close(proc.fd[1]);
		proc.tab = ft_split(av[j], ' ');
		proc.path = ft_get_cmdpath(env, *proc.tab);
		if (execve(proc.path, &proc.tab[0], env) == -1)
		{
			ft_freesplit (proc.tab);
			ft_errexcev(av[j]);
			exit (EXIT_FAILURE);
		}
	}
}

void	ft_lastprocess(t_data proc, char **av, char **env, int ac)
{
	proc.pidmid = fork();
	if (proc.pidmid < 0)
		exit(EXIT_FAILURE);
	if (proc.pidmid)
	{
		close(proc.fd[1]);
		close(proc.fd[0]);
		waitpid(proc.pidmid, NULL, 0);
	}
	else
	{
		close(proc.fd[0]);
		dup2(proc.file2, 1);
		close(proc.fd[1]);
		proc.tab = ft_split(av[ac - 2], ' ');
		proc.path = ft_get_cmdpath(env, *proc.tab);
		if (execve(proc.path, &proc.tab[0], env) == -1)
		{
			ft_freesplit (proc.tab);
			ft_errexcev(av[ac - 2]);
			exit (EXIT_FAILURE);
		}
	}
}
