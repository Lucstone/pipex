/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:38:01 by lnaidu            #+#    #+#             */
/*   Updated: 2023/03/03 17:43:18 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../Libft/srclib/libft.h"
# include "../Libft/gnl/get_next_line.h"
# include "../Libft/printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>

char	*find_path(char **env);
char	**get_path(char **env);
char	*get_cmdpath(char **paths, char *cmd);
void	freesplit(char **tab);

typedef struct s_data
{
	int		file1;
	int		file2;
	int		mid;
	int		fd[2];
	int		i;
	int		j;
	int		pid1;
	int		tmp;
	int		pidmid;
	char	*path;
	char	**tab;
}				t_data;

void	firstprocess(t_data proc, char **av, char **env);
void	lastprocess(t_data proc, char **av, char **env, int ac);
void	midprocess(t_data proc, char **av, char **env, int j);
int		err(char *str);
void	ft_close(t_data prog);

#endif