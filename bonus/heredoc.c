/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:10:05 by lnaidu            #+#    #+#             */
/*   Updated: 2023/03/08 17:48:38 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_openfile1(char **av, t_data prog)
{
	if (!ft_strncmp("here_doc", av[1], 9))
		prog.file1 = ft_heredoc(prog, av);
	else
	{
		prog.file1 = open (av[1], O_RDONLY);
		if (prog.file1 < 0)
			return (1);
	}
	return (prog.file1);
}

int	ft_heredoc(t_data hdoc, char **av)
{
	int		tmp;
	char	*buf;

	tmp = open(".filetmp", O_TRUNC | O_CREAT | O_RDWR, 0666);
	if (tmp < 0)
		return (1);
	while (1)
	{
		write(1, "pipe heredoc> ", 14);
		(buf = get_next_line(0));
		if (!buf || (buf < 0))
			break ;
		if (!ft_strncmp(av[2], buf, (ft_strlen(av[2]))))
		{
			if ((ft_strlen(av[2]) + 1) == (ft_strlen(buf)))
				break ;
		}
		write(tmp, buf, ft_strlen(buf));
		free(buf);
	}
	free(buf);
	close(tmp);
	hdoc.file1 = open(".filetmp", O_RDONLY);
	unlink(".filetmp");
	return (hdoc.file1);
}
