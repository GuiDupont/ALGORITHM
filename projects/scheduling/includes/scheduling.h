#ifndef SCHEDULING_H
# define SCHEDULING_H


#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct	s_jobs
{
	int l;
	int w;
	int diff;
	float ratio;
}				t_jobs;

void	ft_quicksort_j(t_jobs **array, int size);
void	ft_insertionsort_j_w_d(t_jobs **array, int nb_elem);
void	ft_swap_j(t_jobs **a, t_jobs **b);
#endif
