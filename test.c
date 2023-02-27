/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:41:40 by lnaidu            #+#    #+#             */
/*   Updated: 2023/02/27 16:37:54 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*int main(int ac, char ** av)
{
	int idx;
	int idx2;
	int n;
	int i;
	
	idx = fork();
	idx2 = fork();
	(void) ac;
	(void) av;
	//n = 0;
	if (idx == 0)
	{
		if (idx2 == 0)
			printf("la valeur de ix2 child y\n");
		else
			printf("la valeur de ix2 parent x\n");
	}
	else
	{
		if (idx2 == 0)
			printf("la valeur de child z\n");
		else
			printf("la valeur parent \n");
	}
	while (wait(NULL) != -1 || errno != ECHILD)
		printf("Wait for child to finish \n");
	if (idx == 0)
		n = 1;
	else
		n = 6;
	if (idx != 0)
		wait (0);
	i = n;
	while (i < (n + 5))
	{
		printf ("%d ", i);
		i++;
		fflush(stdout);
	}
	if (idx != 0)
		printf("\n");

	return (0);
}*/

/*int main(int argc, char *argv[], char *env[])
{
  if (argc > 1)
    if (execve(argv[1], argv + 1, env) == -1)
      perror("execve");

  printf("My pid is: %d\n", getpid());

  return 0;
}*/

int	main(int ac, char **av, char **env)
{
	t_data	prog;
	int		fd[2];
	
	/*prog.file1 = open (av[1], O_RDONLY);
	if (prog.file1 < 0)
	{
		perror("Error");
		return(0);
	}*/
	if (ac > 1)
	{
		//fd[0] = read;
		//fd[1] = write;
		if (pipe(fd) == -1)
			return (1);
		prog.tab = ft_split(av[1], ' ');
		prog.path = get_cmdpath(env, *prog.tab);
		if (execve(prog.path, &prog.tab[0], env) == -1)
		{
			perror("execve");
			freesplit (prog.tab);
			//system("leaks pipex");
			return (0);
		}
	}
	//system("leaks pipex");
	return (0);
}