NAME		= push_swap

SRCS		=	utils.c \
				utils2.c \
				instructions.c \
				lis.c \
				push_swap_utils.c \
				small_set.c \
			  	main.c

OBJS		= ${SRCS:.c=.o}

RM			= rm -f

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

%.c%.o:
			${CC} ${CFLAGS} $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${ARCHIVE} $(NAME)

re:			fclean all
