##
## Makefile for allum1 in /home/ghost/rendu/C_Prog_Elem/CPE_2015_Allum1
## 
## Made by Baptiste Veyssiere
## Login   <veyssi_b@epitech.net>
## 
## Started on  Wed Feb 10 16:20:33 2016 Baptiste Veyssiere
## Last update Mon Feb 15 16:25:15 2016 Baptiste Veyssiere
##

NAME	= allum1

SRCS	= src/allum1.c		\
	src/my_getnbr.c		\
	src/my_memset.c		\
	src/draw_tab.c		\
	src/my_realloc.c	\
	src/turn.c		\
	src/my_strlen.c		\
	src/check_nbr.c		\
	src/my_put_posnbr.c	\
	src/ai.c		\
	src/check_end.c		\
	src/marienbad.c

OBJS	= $(SRCS:.c=.o)

CC	= gcc

RM	= rm -f

DEBUG	= no

ifeq ($(DEBUG), yes)
	CFLAGS	= -W -Werror -Wall -Wextra -ansi -pedantic -I./include -g
else
	CFLAGS	= -W -Werror -Wall -Wextra -ansi -pedantic -I./include
endif

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)
ifeq ($(DEBUG), yes)
	@echo "Génération en mode débug"
else
	@echo "Génaration en mode release"
endif

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
