SRCS		=	../src/conc.c		\
		../src/delay.c		\
		../src/linux.c		\
		../src/updater.c	\
		../src/windows.c

OBJS		=	$(SRCS:.c=.o)

NAME		=	../updater

CC		=	gcc -std=c99

RM		=	rm -f

CFLAGS		=	-Wall -Wextra -fno-builtin -I../include

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
