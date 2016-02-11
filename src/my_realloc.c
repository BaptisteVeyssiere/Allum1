/*
** my_realloc.c for mysh in /home/VEYSSI_B/rendu/Programmation_Shell/PSU_2015_minishell/test1
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Tue Jan 12 13:39:43 2016 Baptiste veyssiere
** Last update Wed Feb 10 17:38:16 2016 Baptiste Veyssiere
*/

#include "allum1.h"

char	*my_realloc(char *ptr, int size)
{
  char	*tmp;
  int	i;

  tmp = NULL;
  i = -1;
  if ((tmp = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  my_memset(tmp, (size + 1));
  while (ptr[++i] != 0 && i <= size)
    tmp[i] = ptr[i];
  free(ptr);
  ptr = tmp;
  return (ptr);
}
