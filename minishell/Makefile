NAME			=	minishell

SRCS			=	$(shell find src/ -type f -name '*.c')

OBJS			=	${SRCS:%.c=%.o}

LIBSDIR			=	libs
LIBFTDIR		=	${LIBSDIR}/libft

LINKED_LIBS		=	-lft -lreadline

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -f

%.o:				%.c
					${CC} ${CFLAGS} -I${LIBFTDIR} -c $< -o $@

all:				${NAME}
${NAME}:			${OBJS} ${LIBFTDIR}/libft.a
					${CC} ${CFLAGS} -I${LIBFTDIR} ${OBJS} -L${LIBFTDIR} ${LINKED_LIBS} -o ${NAME}

${LIBFTDIR}/libft.a:
					make -C ${LIBFTDIR} libft.a

clean:
					${RM} ${OBJS}
					make -C ${LIBFTDIR} clean
fclean:				clean
					${RM} ${NAME}
					make -C ${LIBFTDIR} fclean

re:					fclean all

.PHONY:				all clean fclean re
