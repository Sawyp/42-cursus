NAME		= pipex

SRCS		=	join.c \
				path.c \
				split.c \
			  	main.c

OBJS		= ${SRCS:.c=.o}

RM			= rm -f

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

%.c%.o:
			${CC} ${CFLAGS} $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME)

re:			fclean all
