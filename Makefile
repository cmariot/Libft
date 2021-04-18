NAME = libft.a

SRCS = *.c

OBJS = ${SRCS:.c=.o}

HEAD = libft.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = ./

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME): $(SRCS) libft.h
	gcc -Wall -Wextra -Werror -I $(INCLUDES) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
		rm -f ${OBJS}

fclean:		clean
		rm -f ${NAME}

re:		fclean all
