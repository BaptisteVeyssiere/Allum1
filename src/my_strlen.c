/*
** my_strlen.c for my_strlen in /home/ghost/rendu/C_Prog_Elem/CPE_2015_Allum1
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Wed Feb 10 17:29:10 2016 Baptiste Veyssiere
** Last update Wed Feb 10 17:30:37 2016 Baptiste Veyssiere
*/

#include "allum1.h"

int	my_strlen(char *s)
{
  int	i;

  i = -1;
  while (s[++i] != 0);
  return (i);
}
