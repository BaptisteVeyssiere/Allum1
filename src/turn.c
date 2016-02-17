/*
** turn.c for allum1 in /home/ghost/rendu/C_Prog_Elem/CPE_2015_Allum1
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Wed Feb 10 17:12:45 2016 Baptiste Veyssiere
** Last update Wed Feb 17 17:31:28 2016 Baptiste Veyssiere
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
      if (buffer[0] != '\n' && buffer[0] > 0)
	{
	  str_nb[++i] = buffer[0];
	  if ((str_nb = my_realloc(str_nb, (my_strlen(str_nb) + 1))) == NULL)
	    return (-1);
	}
    }
  return (free_strdata(str_nb, nbr));
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

int	your_turn(char **tab, int length, int *binary_tab)
{
  int	line_nbr;
  int	line_pass;
  int	matches_pass;
  int	matches;

  init_turn(&line_pass, &matches_pass);
  while (line_pass == 0 && matches_pass == 0)
    {
      if (line_passfunc(&line_nbr, tab, length, &line_pass) == -1)
	return (-1);
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
  aff_player(tab, length, line_nbr, matches);
  binary_tab[line_nbr - 1] -= matches;
  return (0);
}
