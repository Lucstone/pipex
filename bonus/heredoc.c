/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:10:05 by lnaidu            #+#    #+#             */
/*   Updated: 2023/03/03 17:43:21 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	openfile1(char **av, t_data prog)
{
	if(!ft_strncmp("here_doc", av[1], 9))
		heredoc(prog);
	else
		{
			prog.file1 = open (av[1], O_RDONLY);
			if (prog.file1 < 0)
				return ;
		}
}

void	heredoc(t_data hdoc)
{
	int	tmp;

	hdoc.tmp = open (".file.tmp" , O_TRUNC | O_CREAT | O_RDWR, 0666);
	if (hdoc.tmp < 0)
		return ;
	
}

#define BUFFER_SIZE 256

int main(void) {
  char buffer[BUFFER_SIZE];
  char delimiter[BUFFER_SIZE];
  char *line;
  size_t delimiter_len;
  
  printf("Entrez le délimiteur (terminateur) de document ici : ");
  fgets(delimiter, BUFFER_SIZE, stdin);
  
  // Supprime le caractère de saut de ligne ajouté par fgets.
  delimiter_len = strlen(delimiter);
  if (delimiter[delimiter_len - 1] == '\n') {
    delimiter[delimiter_len - 1] = '\0';
    delimiter_len--;
  }
  
  printf("Entrez le document ici (terminé par %s) :\n", delimiter);
  
  // Boucle pour lire les lignes du document.
  while ((line = fgets(buffer, BUFFER_SIZE, stdin))) {
    // Vérifie si la ligne est le terminateur du document.
    if (strncmp(line, delimiter, delimiter_len) == 0) {
      break;
    }
    
    // Affiche la ligne.
    printf("%s", line);
  }
  
  return 0;
}

#include <stdio.h>

#define O_RDONLY 0

FILE *mon_fopen(const char *filename, const char *mode) {
  FILE *fichier;

  // Vérifier que les arguments sont valides
  if (filename == NULL || mode == NULL) {
    return NULL;
  }

  // Ouvrir le fichier en lecture seule
  if ((fichier = (FILE *) open(filename, O_RDONLY)) == NULL) {
    return NULL;
  }

  return fichier;
}