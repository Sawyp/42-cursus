NAME		=	libft.a

SRCS		=	ft_abs.c \
				ft_atoi.c \
				ft_atol.c \
				ft_atoll.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_fdprintf.c \
				ft_free_strs.c \
				ft_get_next_line.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isblank.c \
				ft_iscntrl.c \
				ft_isdigit.c \
				ft_isgraph.c \
				ft_islower.c \
				ft_isprint.c \
				ft_ispunct.c \
				ft_isspace.c \
				ft_isupper.c \
				ft_isxdigit.c \
				ft_itoa.c \
				ft_lltoa.c \
				ft_lltoa_base.c \
				ft_log.c \
				ft_lvec/ft_lvec_alloc.c \
				ft_lvec/ft_lvec_element_lookup.c \
				ft_lvec/ft_lvec_managment.c \
				ft_svec/ft_svec_alloc.c \
				ft_svec/ft_svec_element_lookup.c \
				ft_svec/ft_svec_managment.c \
				ft_max.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_memswap.c \
				ft_min.c \
				ft_printf.c \
				ft_printf/code_handling.c \
				ft_printf/ft_string.c \
				ft_printf/generate_formatted_str.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putllnbr_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_putstrn_fd.c \
				ft_realloc.c \
				ft_s_atoi.c \
				ft_s_atol.c \
				ft_s_atoll.c \
				ft_split.c \
				ft_strcat.c \
				ft_strchr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncat.c \
				ft_strnchr.c \
				ft_strncmp.c \
				ft_strncpy.c \
				ft_strndup.c \
				ft_strnlen.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strsnjoin.c \
				ft_strstr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_ulltoa_base.c
OBJS		=	${SRCS:.c=.o}

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

%.o: %.c
				${CC} ${CFLAGS} -c $< -o $@

all:			${NAME}
${NAME}:		${OBJS}
				ar rcs ${NAME} ${OBJS}

clean:
				${RM} ${OBJS}
fclean:			clean
				${RM} ${NAME} ${NAME}_tests

re:				fclean all

.PHONY:			all clean fclean re