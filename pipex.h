/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:38:01 by lnaidu            #+#    #+#             */
/*   Updated: 2023/02/27 16:21:49 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./Libft/srclib/libft.h"
# include "./Libft/gnl/get_next_line.h"
# include "./Libft/printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>

char	*find_path(char **env);
char	**get_path(char **env);
char	*get_cmdpath(char **paths, char *cmd);
void freesplit(char **tab);

typedef struct s_data
{
	int		file1;
	int		file2;
	char	*path;
	char	**tab;
}				t_data;


#endif