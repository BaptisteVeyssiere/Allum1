/*
** allum1.c for allum1 in /home/ghost/rendu/C_Prog_Elem/CPE_2015_Allum1
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Wed Feb 10 16:26:24 2016 Baptiste Veyssiere
** Last update Wed Feb 17 16:07:13 2016 Baptiste Veyssiere
*/

#include "allum1.h"

void	fill_tab(char **tab, int length)
{
  int	i;
  int	j;
  int	lim_inf;
  int	lim_sup;

  i = length;
  lim_inf = 0;
  lim_sup = length * 2 - 2;
  while (--i > -1)
    {
      j = -1;
      while (++j < ((length * 2) - 1))
	{
	  if (j >= lim_inf && j <= lim_sup)
	    tab[i][j] = 1;
	}
      ++lim_inf;
      --lim_sup;
    }
}

void	free_tab(char **tab, int length)
{
  int	i;

  i = -1;
  while (++i < length)
    free(tab[i]);
  free(tab);
}

char	**init_tab(char **tab, int length)
{
  int	i;

  if ((tab = malloc(sizeof(char*) * (length + 1))) == NULL)
    return (NULL);
  i = -1;
  while (++i < length)
    {
      if ((tab[i] = malloc(sizeof(char) * (length * 2))) == NULL)
	return (NULL);
      my_memset(tab[i], (length * 2));
    }
  tab[length] = NULL;
  fill_tab(tab, length);
  return (tab);
}

int	allum(int length)
{
  char	**tab;
  int	end;
  int	*binary_tab;

  if (((tab = NULL) != NULL) || (tab = init_tab(tab, length)) == NULL ||
      (binary_tab = init_binary(length)) == NULL || (end = 0) != 0)
    return (-1);
  draw_tab(tab, length);
  while (end == 0)
    {
      if (your_turn(tab, length, binary_tab) == -1)
	return (freefunc(tab, binary_tab, length, -1));
      draw_tab(tab, length);
      if (check_end(tab, length, 0) == 1)
	end = 1;
      else
	{
	  if (ai_turn(tab, length, binary_tab) == -1)
	    return (freefunc(tab, binary_tab, length, -1));
	  draw_tab(tab, length);
	  if (check_end(tab, length, 1) == 1)
	    end = 1;
	}
    }
  return (freefunc(tab, binary_tab, length, 0));
}

int	main(int ac, char **av)
{
  if (ac == 1 || check_nbr(av[1]) == 1)
    {
      if (allum(4) == -1)
	return (-1);
    }
  else if (allum(my_getnbr(av[1])) == -1)
    return (-1);
  return (0);
}
