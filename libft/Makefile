NAME= libft.a

CC= gcc

CFLAGS= -Wall -Wextra -Werror

PATH_SRCS = srcs

SRCS_LST	= \
		libft/ft_strcat.c libft/ft_strcmp.c \
		libft/ft_strdup.c libft/ft_striteri.c \
		libft/ft_strlcpy.c libft/ft_strncat.c \
		libft/ft_strnew.c libft/ft_strstr.c \
		libft/ft_strchr.c libft/ft_strcpy.c \
		libft/ft_strequ.c libft/ft_strjoin.c \
		libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strtrim.c \
		libft/ft_strclr.c libft/ft_strdel.c libft/ft_striter.c libft/ft_strlcat.c \
		libft/ft_strmapi.c libft/ft_strnequ.c libft/ft_strrchr.c \
		\
		libft/ft_calloc.c  libft/ft_split.c  libft/ft_substr.c  libft/ft_bzero.c \
		libft/ft_free_split.c  libft/ft_array_length.c libft/ft_join2d.c \
		libft/ft_print_split.c libft/ft_count_split.c libft/ft_arraycpy.c\
		\
		libft/ft_lstadd_back.c  libft/ft_lstclear.c  libft/ft_lstiter.c \
		libft/ft_lstmap.c  libft/ft_lstsize.c  libft/ft_lstadd_front.c \
		libft/ft_lstdelone.c   libft/ft_lstlast.c   libft/ft_lstnew.c \
		\
		libft/ft_memalloc.c  libft/ft_memccpy.c  libft/ft_memchr.c \
		libft/ft_memcmp.c  libft/ft_memcpy.c  libft/ft_memdel.c  libft/ft_memmove.c \
		libft/ft_memset.c \
		\
		libft/ft_putchar.c  libft/ft_putchar_fd.c  libft/ft_putendl.c \
		libft/ft_putendl_fd.c  libft/ft_putnbr.c  libft/ft_putnbr_fd.c \
		libft/ft_putstr.c  libft/ft_putstr_fd.c libft/print_array.c \
		\
		libft/ft_isalnum.c  libft/ft_isalpha.c  libft/ft_isascii.c \
		libft/ft_isdigit.c  libft/ft_isprint.c  libft/ft_tolower.c  libft/ft_toupper.c \
		libft/ft_s_isdigit.c \
		\
		libft/ft_atoi.c  libft/ft_itoa.c  libft/ft_itoa_u.c \
		libft/ft_ul_to_p.c  libft/ft_atof.c \
		\
		libft/ft_swap.c \
		\
		ft_printf/ft_printf.c \
		ft_printf/valid_config.c \
		ft_printf/printing_global.c \
		ft_printf/printing_s_c_percentage.c \
		ft_printf/printing_d_i_u.c \
		ft_printf/printing_p_x.c \
		ft_printf/ft_u_to_x.c \
		ft_printf/ft_abs_l.c \
		ft_printf/print_single_char.c \
		ft_printf/printing_tools.c \
		ft_printf/tools_config.c \
		ft_printf/tools_2.c \
		ft_printf/tools.c \
		\
		gnl/get_next_line.c gnl/get_next_line_utils.c \
		\
		algo_lib/ft_arraycpy.c algo_lib/ft_print_array.c algo_lib/ft_bzero_arrays.c algo_lib/ft_print_arrays.c algo_lib/ft_randomize_array.c \
		algo_lib/ft_malloc_arrays.c algo_lib/ft_put_txt_in_array.c \
        algo_lib/ft_swap.c \
        algo_lib/ft_quicksort.c algo_lib/ft_mergesort.c algo_lib/ft_insertionsort.c 

SRCS= $(addprefix ${PATH_SRCS}/, ${SRCS_LST})

OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@ 

so: $(NAME)
	$(CC) -shared -o libft.so *.o ft_printf/*.o gnl/*.o algo_lib/*.o
 
clean: 
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)
	rm -f libft.so

re: fclean all

reso: fclean so

.PHONY: clean fclean bonus
