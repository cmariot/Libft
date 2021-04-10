NAME	= libft.a

SRCS	= *.c

OBJS	= *.o

HEAD	= libft.h

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror


${NAME}:	
		${CC} ${CFLAGS} ${SRCS}

all :		${NAME}

clean:
		rm -f ${OBJS}

fclean:		clean
		rm -f ${NAME}

re:		fclean all
