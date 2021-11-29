CC = gcc
FLAGS = -Wall -Wextra -Werror -g
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
		ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memcpy.c\
		ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c
OBJS = ${SRC:.c=.o}
SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS_BONUS = ${SRC_BONUS:.c=.o}
NAME = libft.a
RM = rm -f

.c.o: libft.h
	  ${CC} ${FLAGS} -I. -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
		ar rc ${NAME} ${OBJS}
		${CC} ${OBJS} -L. -lft ${NAME}

all: ${NAME}

bonus:${OBJS} ${OBJS_BONUS}
	  ar rc ${NAME} ${OBJS} ${OBJS_BONUS}
	  ${CC} ${OBJS} ${OBJS_BONUS} -L. -lft ${NAME}

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

clean:
		${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
		${RM} ${NAME}

re: fclean all
