/*
** ai.c for allum1 in /home/ghost/rendu/C_Prog_Elem/CPE_2015_Allum1
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Fri Feb 12 00:38:57 2016 Baptiste Veyssiere
** Last update Sat Feb 13 02:31:34 2016 Baptiste Veyssiere
*/

#include "allum1.h"

int	get_xor(int *binary_tab, int length)
{
  int	i;
  int	xor_tot;

  i = -1;
  xor_tot = 0;
  while (++i < length)
    xor_tot = xor_tot^(binary_tab[i]);
  return (xor_tot);
}

int	get_goodline(int length, int *binary_tab, int xor_tot)
{
  int	position;
  int	line;

  line = 0;
  position = 0;
  while ((xor_tot >> (position + 1)) > 0)
    ++position;
  while (((((1 << position) & binary_tab[line])) >> position) == 0 && line < length)
    ++line;
  if (line == length)
    return (-1);
  return (line + 1);
}

int	get_new_matches(int xor_tot, int nbr)
{
  int	new_matches;
  int	i;

  i = 0;
  while ((xor_tot >> (i + 1)) > 0)
    ++i;
  new_matches = nbr^(1 << i);
  while (--i >= 0)
    if ((((1 << i) & xor_tot) >> i) == 1)
      {
	if ((((1 << i) & nbr) >> i) == 1)
	  new_matches = 0;
	else
	  new_matches = 1;
      }
  return (new_matches);
}

int	ai_algo(int length, int *line, int *binary_tab)
{
  int	new_matches;
  int	xor_tot;

  new_matches = 0;
  xor_tot = get_xor(binary_tab, length);
  if ((*line = get_goodline(length, binary_tab, xor_tot)) == -1)
    {
      *line = (rand() % length) + 1;
      new_matches = rand() % binary_tab[*line - 1];
    }
  else
    {
      new_matches = get_new_matches(xor_tot, binary_tab[*line - 1]);
    }
  return (new_matches);
}

int	ai_turn(char **tab, int length, int *binary_tab)
{
  int	line;
  int	matches;
  int	new_matches;

  line = 0;
  matches = 0;
  if (check_marienbad(binary_tab, length) == 1)
    new_matches = marienbad_xor(length, &line, binary_tab);
  else if ((new_matches = ai_algo(length, &line, binary_tab)) == -1)
    return (-1);
  matches = binary_tab[line - 1] - new_matches;
  write(1, "\nAI's turn...\nAI removed ", 25);
  my_put_posnbr(matches);
  write(1, " match(es) from line ", 21);
  my_put_posnbr(line);
  write(1, "\n", 1);
  binary_tab[line - 1] -= matches;
  remove_allum(tab, length, line, matches);
  return (0);
}
