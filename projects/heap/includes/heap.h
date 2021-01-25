#ifndef HEAP_H
# define HEAP_H

#include "../../../libft/includes/libft.h"

typedef struct	s_heap
{
	int *array;
	int size;
}				t_heap;

t_heap	*malloc_heap(int max_size);
void	free_heap(t_heap *to_free);
void	ft_insert_heap_min(t_heap *heap, int numb);
void	ft_insert_heap_max(t_heap *heap, int numb);
void	ft_pop_max_heap(t_heap *heap);
int		ft_pop_min_heap(t_heap *heap);

#endif
