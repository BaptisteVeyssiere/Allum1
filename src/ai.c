/*
** ai.c for allum1 in /home/ghost/rendu/C_Prog_Elem/CPE_2015_Allum1
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Fri Feb 12 00:38:57 2016 Baptiste Veyssiere
** Last update Fri Feb 12 00:48:26 2016 Baptiste Veyssiere
*/

#include "allum1.h"

int	ai_turn(char **tab, int length)
{
  tab = tab;
  length = length;
  write(1, "\nAI's turn...\nAI removed ", 25);
  my_put_posnbr(1);
  write(1, " match(es) from line ", 21);
  my_put_posnbr(1);
  write(1, "\n", 1);
  return (0);
}
