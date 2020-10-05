#ifndef ALGO_H
# define ALGO_H

#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
#include <fcntl.h>

#include "../libft/libft.h"

void	bzero_arrays(int **array, int nb_lines, int line_size);
void	print_array(int *array, int size);
void	print_arrays(int **arrays, int nb_lines, int line_size);
void	randomize_arrays(int **array, int nb_lines, int line_size, int max_value);
void	randomize_array(int *array, int line_size, int max_value);


int		***create_arrays(int ***arrays, int nb_lines, int size_line);

int		*count_occurences(int *array, int size, int max_value);

void	ft_swap(int *a, int *b);

void	ft_quicksort(int *array, int index_minimun, int index_max);
void	insertion_sort(int *array, int number_elem);

#endif
