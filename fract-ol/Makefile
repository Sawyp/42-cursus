NAME		= fractol

SRCS		=	color.c \
				events.c \
				parsing.c \
				render.c \
			  	main.c

OBJS		= ${SRCS:.c=.o}

RM			= rm -f

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

LIBS		= minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm

%.c%.o:
			${CC} ${CFLAGS} $< -o ${<:.c=.o}

all:		${NAME}

minilibx-linux/libmlx_Linux.a:
								make -C minilibx-linux/

${NAME}:	${OBJS} minilibx-linux/libmlx_Linux.a
			${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${ARCHIVE} $(NAME)

re:			fclean all
