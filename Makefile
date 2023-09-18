NAME = push_swap
SRCS = ./srcs/push_swap.c ./srcs/ope.c ./srcs/rotate.c ./srcs/sort_5.c ./srcs/sort.c ./srcs/utils.c ./srcs/utils2.c \
./srcs/stack.c 

OBJS = ${SRCS:.c=.o}

INCLUDE = ./includes/push_swap.c
LIBFT = ./includes/libft/libft.a
FLAGS = -Wall -Werror -Wextra

%.o: %.c ${INCLUDE}
	cc ${FLAGS} -I ${INCLUDE} -c $< -o

${NAME}: ${OBJS}
	make -C ./libft
	cc ${OBJS} -L ./libft -l ft -o ${NAME}

all: ${NAME}

clean:
	make clean -C ./libft
	rm -f ${OBJS}

fclean: clean
	make fclean -C ./libft
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
