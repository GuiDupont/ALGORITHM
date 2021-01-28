# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/25 11:29:54 by gdupont           #+#    #+#              #
#    Updated: 2021/01/28 15:13:35 by gdupont          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = prob2sum

CC = gcc

FLAGS = -Wall -Wextra -Werror

PATH_SRCS = srcs

SRCS_LIST		= prob2sum.c tools.c


SRCS = $(addprefix ${PATH_SRCS}/, ${SRCS_LIST})

OBJS = $(SRCS:.c=.o)

INCLUDES = -I./includes

LIBFT = ../../libft

LFLAGS	= -L $(LIBFT) -lft

SGFLAGS = -g ulimit -c unlimited

FFLAGS = -g3 -fsanitize=address

$(NAME) :	$(OBJS) 
	@make -C $(LIBFT)
	$(CC) $(FLAGS) $(LFLAGS) $(FFLAGS) $(INCLUDES) $(OBJS) $(LIBFT)/libft.a -o $(NAME) 

all : $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) $(FFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@make clean -s -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re bonus

