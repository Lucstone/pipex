/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:24:51 by lnaidu            #+#    #+#             */
/*   Updated: 2023/02/24 15:29:48 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **env)
{
	while ((env) && (ft_strncmp("PATH=",*env, 5)))
		env++;
	if (env)
		return (*env + 5);
	return (0);
}

char	**get_path(char **env)
{
	char	**path;

	path = ft_split((find_path(env)), ':');
	return (path);
}

char	*get_cmdpath(char **paths, char *cmd)
{
	char	*tmp;
	char	**path;

	path = get_path(paths);
	while (*path)
	{
		tmp = ft_strjoin((ft_strjoin(path[0], "/")), cmd);
		if (access(tmp, F_OK)== 0)
			return (tmp);
		path++;
	}
	return (NULL);
}
