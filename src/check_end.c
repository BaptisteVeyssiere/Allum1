/*
** check_end.c for allum1 in /home/ghost/rendu/C_Prog_Elem/CPE_2015_Allum1
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Fri Feb 12 00:45:09 2016 Baptiste Veyssiere
** Last update Fri Feb 12 00:50:47 2016 Baptiste Veyssiere
*/

#include "allum1.h"

int	check_end(char **tab, int length, char player)
{
  int	i;
  int	j;

  i = -1;
  while (++i < length)
    {
      j = -1;
      while (++j < ((length * 2) - 1))
	if (tab[i][j] == 1)
	  return (0);
    }
  if (player == 0)
    write(1, "You lost, too bad..\n", 20);
  else
    write(1, "I lost.. snif.. but I'll get you next time!!\n", 45);
  return (1);
}
