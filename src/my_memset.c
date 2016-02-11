/*
** my_memset.c for allum1 in /home/ghost/rendu/C_Prog_Elem/CPE_2015_Allum1
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Wed Feb 10 16:42:51 2016 Baptiste Veyssiere
** Last update Wed Feb 10 16:45:44 2016 Baptiste Veyssiere
*/

void	my_memset(char *str, int length)
{
  int	i;

  i = -1;
  while (++i < length)
    str[i] = 0;
}
