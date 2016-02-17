/*
** allum1.h for allum1 in /home/ghost/rendu/C_Prog_Elem/CPE_2015_Allum1
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Wed Feb 10 16:25:23 2016 Baptiste Veyssiere
** Last update Wed Feb 17 15:48:53 2016 Baptiste Veyssiere
*/

#ifndef ALLUM1_H_
# define ALLUM1_H_

#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int	allum(int);
int	my_getnbr(char*);
void	free_tab(char**, int);
char	**init_tab(char**, int);
void	my_memset(char*, int);
void	fill_tab(char**, int);
void	draw_tab(char**, int);
int	your_turn(char**, int, int*);
char	*my_realloc(char*, int);
int	get_data();
int	my_strlen(char*);
int	check_nbr(char*);
int	test_line(char**, int, int);
int	test_matches(char**, int, int, int);
void	my_put_posnbr(int);
void	remove_allum(char**, int, int, int);
int	check_end(char**, int, char);
int	ai_turn(char**, int, int*);
int	check_str(char*);
int	ai_algo(int, int*, int*);
int	get_goodline(int, int*, int);
int	get_xor(int*, int);
int	*init_binary(int);
int	check_marienbad(int*, int);
int	marienbad_xor(int, int*, int*);
int	freefunc(char**, int*, int, int);
void	aff_player(char**, int, int, int);
int	line_passfunc(int*, char**, int, int*);

#endif /* !ALLUM1_H_ */
