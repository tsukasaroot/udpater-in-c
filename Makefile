##
## makefile for make in /home/jordan.roucom/CPool_rush3
##
## Made by Jordan Rouco miguez
## Login   <jordan.roucom@epitech.net>
##
## Last update Fri Nov 25 16:46:39 2016 Jordan Rouco miguez
##

CC	=	i586-mingw32msvc-gcc -std=c99

SRCS	=	src/conc.c	\
		src/linux.c	\
		src/windows.c	\
		src/updater.c	\
		src/delay.c

RM	=	rm -f

OBJS	=	$(SRCS:.c=.o)

NAME	=	updater.exe

CFLAGS	=	-Wall -Wextra -Werror

all:	$(NAME)

$(NAME): $(OBJS)
	$(OPT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
