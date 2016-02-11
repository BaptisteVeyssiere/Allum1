/*
** check_nbr.c for allum1 in /home/ghost/rendu/C_Prog_Elem/CPE_2015_Allum1
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Wed Feb 10 17:42:49 2016 Baptiste Veyssiere
** Last update Wed Feb 10 17:49:31 2016 Baptiste Veyssiere
*/

#include "allum1.h"

int	check_nbr(char *str)
{
  int	i;

  i = -1;
  while (++i < my_strlen(str))
    if (str[i] < '0' || str[i] > '9')
      return (1);
  if (my_getnbr(str) < 2)
    return (1);
  return (0);
}
