/*
** allum1.h for allum1 in /home/ghost/rendu/C_Prog_Elem/CPE_2015_Allum1
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Wed Feb 10 16:25:23 2016 Baptiste Veyssiere
** Last update Fri Feb 12 00:47:46 2016 Baptiste Veyssiere
*/

#ifndef ALLUM1_H_
# define ALLUM1_H_

#include <stdlib.h>
#include <unistd.h>

int	allum(int);
int	my_getnbr(char*);
void	free_tab(char**, int);
char	**init_tab(char**, int);
void	my_memset(char*, int);
void	fill_tab(char**, int);
void	draw_tab(char**, int);
int	your_turn(char**, int);
char	*my_realloc(char*, int);
int	get_data();
int	my_strlen(char*);
int	check_nbr(char*);
int	test_line(char**, int, int);
int	test_matches(char**, int, int, int);
void	my_put_posnbr(int);
void	remove_allum(char**, int, int, int);
int	check_end(char**, int, char);
int	ai_turn(char**, int);

#endif /* !ALLUM1_H_ */
