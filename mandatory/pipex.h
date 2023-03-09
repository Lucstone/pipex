/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:38:01 by lnaidu            #+#    #+#             */
/*   Updated: 2023/03/08 18:51:23 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/srclib/libft.h"
# include "../Libft/gnl/get_next_line.h"
# include "../Libft/printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>

/*COMMAND FUNCTION*/
char	*ft_find_path(char **env);
char	**ft_get_path(char **env);
char	*ft_get_cmdpath(char **paths, char *cmd);
void	ft_freesplit(char **tab);

typedef struct s_data
{
	int		file1;
	int		file2;
	int		mid;
	int		fd[2];
	int		i;
	int		j;
	int		pid1;
	int		pid2;
	int		tmp;
	int		pidmid;
	char	*path;
	char	**tab;
}				t_data;

/*PROCESS FUNCTION*/
void	ft_firstprocess(t_data proc, char **av, char **env);
void	ft_lastprocess(t_data proc, char **av, char **env, int ac);
void	ft_midprocess(t_data proc, char **av, char **env, int j);
void	ft_firstprocess1(t_data proc, char **av, char **env);
/*ERROR,FREE & OPEN FUNCTION*/
int		ft_err(char *str);
void	ft_close(t_data prog);
int		ft_errexcev(char *str);
int		ft_openfile(char **av, t_data prog);
int		ft_err2(char *str, int fd);
int		ft_open(char **av);

#endif