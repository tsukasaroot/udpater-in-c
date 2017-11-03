##
## makefile for make in /home/jordan.roucom/CPool_rush3
##
## Made by Jordan Rouco miguez
## Login   <jordan.roucom@epitech.net>
##
## Last update Fri Nov  3 18:31:15 2017 Tsukasa
##

CC	=	i686-w64-mingw32-gcc -std=c99

SRCS	=	src/updater.c	\
		src/getver.c	\
		src/utilities.c

RM	=	rm -f

OBJS	=	$(SRCS:.c=.o)

NAME	=	updater.exe

CFLAGS	=	-Wall -Wextra -Werror -fno-builtin -Iinclude

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
