/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:24:51 by lnaidu            #+#    #+#             */
/*   Updated: 2023/03/03 14:45:13 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*find_path(char **env)
{
	while ((ft_strncmp("PATH=",*env, 5)) && env)
		env++;
	if (env)
		return (*env + 5);
	return (0);
}

char	*get_cmdpath(char **env, char *cmd)
{
	char	*tmp;
	char	*tmp2;
	char	**path;
	int		i;

	if (find_path(env) == 0)
		return (0);
	i = 0;
	path = ft_split((find_path(env)), ':');
	while (path[i])
	{
		tmp2 = ft_strjoin(path[i], "/");
		tmp = ft_strjoin(tmp2, cmd);
		free(tmp2);
		if (access(tmp, F_OK) == 0)
		{
			freesplit(path);
			return (tmp);
		}
		free (tmp);
		i++;
	}
	freesplit(path);
	return (NULL);
}
