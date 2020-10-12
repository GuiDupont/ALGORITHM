NAME = sorting_algo

CC = gcc

FLAGS = -Wall -Wextra -Werror

PATH_SRCS = srcs

LIBFT = libft/libft.a

LIN_EXPLAIN = /usr/lib/x86_64-linux-gnu/libexplain.so

SRCS_LIST = 		analyze_array.c generate_arrays.c print_array.c \
					ft_swap.c \
					quicksort.c \
					insertion_sort.c \
					main.c

SRCS = $(addprefix ${PATH_SRCS}/, ${SRCS_LIST})

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
	
