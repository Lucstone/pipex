/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:24:51 by lnaidu            #+#    #+#             */
/*   Updated: 2023/03/07 15:47:08 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

char	*ft_find_path(char **env)
{
	while ((ft_strncmp("PATH=",*env, 5)) && env)
		env++;
	if (env)
		return (*env + 5);
	return (0);
}

char	*ft_get_cmdpath(char **env, char *cmd)
{
	char	*tmp;
	char	*tmp2;
	char	**path;
	int		i;

	if (ft_find_path(env) == 0)
		return (0);
	i = 0;
	path = ft_split((ft_find_path(env)), ':');
	while (path[i])
	{
		tmp2 = ft_strjoin(path[i], "/");
		tmp = ft_strjoin(tmp2, cmd);
		free(tmp2);
		if (access(tmp, F_OK) == 0)
		{
			ft_freesplit(path);
			return (tmp);
		}
		free (tmp);
		i++;
	}
	ft_freesplit(path);
	return (NULL);
}
