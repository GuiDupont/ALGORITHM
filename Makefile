NAME = sorting_algo

CC = gcc

FLAGS = -Wall -Wextra -Werror

PATH_SRCS = srcs

LIBFT = libft

LIN_EXPLAIN = /usr/lib/x86_64-linux-gnu/libexplain.so

SRCS_LIST = 		analyze_array.c generate_arrays.c print_array.c \
					ft_swap.c \
					quick_sort.c \
					insertion_sort.c \
					fusion_sort.c \
					tools.c \
					main.c

SRCS = $(addprefix ${PATH_SRCS}/, ${SRCS_LIST})

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) $(OBJS) libft/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
	
