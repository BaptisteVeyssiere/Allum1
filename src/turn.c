/*
** turn.c for allum1 in /home/ghost/rendu/C_Prog_Elem/CPE_2015_Allum1
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Wed Feb 10 17:12:45 2016 Baptiste Veyssiere
** Last update Fri Feb 12 00:52:40 2016 Baptiste Veyssiere
*/

#include "allum1.h"

int	get_data()
{
  char	buffer[2];
  char	*str_nb;
  int	nbr;
  int	i;

  i = -1;
  nbr = 0;
  if ((str_nb = malloc(sizeof(char) * 2)) == NULL)
    return (-1);
  my_memset(str_nb, 2);
  my_memset(buffer, 2);
  while (buffer[0] != '\n')
    {
      read(0, buffer, 1);
      if ((buffer[0] < '0' || buffer[0] > '9') && buffer[0] != '\n')
	nbr = -1;
      if (buffer[0] != '\n')
	{
	  str_nb[++i] = buffer[0];
	  if ((str_nb = my_realloc(str_nb, (my_strlen(str_nb) + 1))) == NULL)
	    return (-1);
	}
    }
  if (str_nb[0] == 0 || nbr == -1)
    {
      free(str_nb);
      return (-2);
    }
  nbr = my_getnbr(str_nb);
  free(str_nb);
  return (nbr);
}

int	test_line(char **tab, int length, int line_nbr)
{
  int	i;

  if (line_nbr < 0)
    {
      write(1, "Error: invalid input (positive number expected)\n", 48);
      return (1);
    }
  if (line_nbr > length || line_nbr < 1)
    {
      write(1, "Error: this line is out of range\n", 33);
      return (1);
    }
  i = -1;
  while (++i < ((length * 2) - 1) && tab[line_nbr - 1][i] == 0);
  if (tab[line_nbr - 1][i] == 0)
    {
      write(1, "Error: this line is empty\n", 26);
      return (1);
    }
  return (0);
}

int	test_matches(char **tab, int length, int matches, int line)
{
  int	i;
  int	allum;

  if (matches == 0)
    {
      write(1, "Error: you have to remove at least one match\n", 45);
      return (1);
    }
  if (matches < 0)
    {
      write(1, "Error: invalid input (positive number expected)\n", 48);
      return (1);
    }
  i = -1;
  allum = 0;
  while (++i < ((length * 2) - 1))
    if (tab[line - 1][i] == 1)
      ++allum;
  if (allum < matches)
    {
      write(1, "Error: not enough matches on this line\n", 39);
      return (1);
    }
  return (0);
}

void	remove_allum(char **tab, int length, int line, int matches)
{
  int	i;

  i = (length * 2) - 2;
  while (tab[line - 1][i] == 0)
    --i;
  while (matches > 0)
    {
      tab[line - 1][i] = 0;
      --i;
      --matches;
    }
}

int	your_turn(char **tab, int length)
{
  int	line_nbr;
  int	line_pass;
  int	matches_pass;
  int	matches;

  line_pass = 0;
  matches_pass = 0;
  write(1, "\nYour turn:\n", 12);
  while (line_pass == 0 && matches_pass == 0)
    {
      write(1, "Line: ", 6);
      if ((line_nbr = get_data()) == -1)
	return (-1);
      if (test_line(tab, length, line_nbr) == 0)
	line_pass = 1;
      if (line_pass == 1)
	{
	  write(1, "Matches: ", 9);
	  if ((matches = get_data()) == -1)
	    return (-1);
	  if (test_matches(tab, length, matches, line_nbr) == 0)
	    matches_pass = 1;
	  else
	    line_pass = 0;
	}
    }
  write(1, "Player removed ", 15);
  my_put_posnbr(matches);
  write(1, " match(es) from line ", 21);
  my_put_posnbr(line_nbr);
  write(1, "\n", 1);
  remove_allum(tab, length, line_nbr, matches);
  return (0);
}
