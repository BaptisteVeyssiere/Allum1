/*
** draw_tab.c for allum1 in /home/ghost/rendu/C_Prog_Elem/CPE_2015_Allum1
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Wed Feb 10 16:54:15 2016 Baptiste Veyssiere
** Last update Fri Feb 12 00:53:50 2016 Baptiste Veyssiere
*/

#include "allum1.h"

void	draw_tab(char** tab, int length)
{
  int	i;
  int	j;

  i = -1;
  while (++i <= (length * 2))
    write(1, "*", 1);
  write(1, "\n", 1);
  i = -1;
  while (++i < length)
    {
      j = -1;
      write(1, "*", 1);
      while (++j < ((length * 2) - 1))
	if (tab[i][j] == 1)
	  write(1, "|", 1);
	else
	  write(1, " ", 1);
      write(1, "*\n", 2);
    }
  i = -1;
  while (++i <= (length * 2))
    write(1, "*", 1);
  write(1, "\n", 1);
}
