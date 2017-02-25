##
## makefile for make in /home/jordan.roucom/CPool_rush3
##
## Made by Jordan Rouco miguez
## Login   <jordan.roucom@epitech.net>
##
## Last update Sat Feb 25 16:54:05 2017 DESKTOP-D27SM6T
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

OPT	=	cd make_linux && make

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
#	$(OPT)
wclean:
	$(RM) $(OBJS)

clean:
	$(RM) $(OBJS)
#	$(OPT) clean

fclean: wclean
	$(RM) $(NAME)
#	$(OPT) fclean

re: fclean all

.PHONY: all clean fclean re
