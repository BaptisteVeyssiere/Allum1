/*
** turn_bis.c for allum1 in /home/ghost/rendu/C_Prog_Elem/CPE_2015_Allum1/src
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Wed Feb 17 15:39:38 2016 Baptiste Veyssiere
** Last update Wed Feb 17 15:48:29 2016 Baptiste Veyssiere
*/

#include "allum1.h"

void	aff_player(char **tab, int length, int line_nbr, int matches)
{
  write(1, "Player removed ", 15);
  my_put_posnbr(matches);
  write(1, " match(es) from line ", 21);
  my_put_posnbr(line_nbr);
  write(1, "\n", 1);
  remove_allum(tab, length, line_nbr, matches);
}

int	line_passfunc(int *line_nbr, char **tab, int length, int *line_pass)
{
  write(1, "Line: ", 6);
  if ((*line_nbr = get_data()) == -1)
    return (-1);
  if (test_line(tab, length, *line_nbr) == 0)
    *line_pass = 1;
  return (0);
}
