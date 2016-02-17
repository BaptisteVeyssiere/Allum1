/*
** freefunc.c for allum1 in /home/ghost/rendu/C_Prog_Elem/CPE_2015_Allum1/src
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Wed Feb 17 15:15:28 2016 Baptiste Veyssiere
** Last update Wed Feb 17 15:21:03 2016 Baptiste Veyssiere
*/

#include "allum1.h"

int	freefunc(char **tab, int *binary_tab, int length, int val)
{
  free_tab(tab, length);
  free(binary_tab);
  return (val);
}
