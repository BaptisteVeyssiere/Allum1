/*
** marienbad.c for allum1 in /home/ghost/rendu/C_Prog_Elem/CPE_2015_Allum1
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sat Feb 13 02:27:46 2016 Baptiste Veyssiere
** Last update Wed Feb 17 16:36:23 2016 Baptiste Veyssiere
*/

#include "allum1.h"

int	check_marienbad(int *binary_tab, int length)
{
  int	i;
  int	counter;

  i = -1;
  counter = 0;
  while (++i < length)
    if (binary_tab[i] > 1)
      ++counter;
  if (counter == 1)
    return (1);
  return (0);
}

int	marienbad_xor(int length, int *line, int *binary_tab)
{
  int	new_matches;
  int	i;
  int	counter;

  new_matches = 0;
  i = -1;
  counter = 0;
  while (++i < length)
    if (binary_tab[i] == 1)
      ++counter;
    else if (binary_tab[i] > 1)
      *line = i + 1;
  if ((counter % 2) == 0)
    new_matches = 1;
  else
    new_matches = 0;
  return (new_matches);
}
