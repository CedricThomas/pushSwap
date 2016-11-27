##
## Makefile for Makefile in /home/cedric/lib
## 
## Made by Cédric Thomas
## Login   <cedric@epitech.net>
## 
## Started on  Sat Oct 22 10:37:32 2016 Cédric Thomas
## Last update Sat Nov 26 12:15:03 2016 Cédric Thomas
##

SRC	=	main.c				\
		listb.c				\
		lista.c				\
		sort.c				\
		insert_to_lb.c			\
		init_lb.c			\
		misc/my_strcat.c		\
		module/module_list.c		\
		module/module_pushswap.c	

OBJ	=	$(SRC:.c=.o)

NAME	=	push_swap

LIB_F	=	./lib/

LIB	=	my

INCLUDE	=	-I./include/

CFLAGS	+=	 $(INCLUDE) -g	


all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -L$(LIB_F) -l$(LIB)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONE: all clean fclean re
