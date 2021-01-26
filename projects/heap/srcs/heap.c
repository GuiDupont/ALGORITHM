#include "../includes/heap.h"

/*
** This function does 2 things, first it select which heap to put the new number in.
** If the number is inferior to the max number of the heap inf (which is a heap max)
** it goes in it. Reciprocly for the heap sup (which is a heap min).
*/

void	add_numb_in_one_of_the_two_heaps(t_heap *heap_inf, t_heap *heap_sup, int number)
{
	if (heap_inf->size == 0 || number < heap_inf->array[1])
		ft_insert_heap_max(heap_inf, number);
	else
		ft_insert_heap_min(heap_sup, number);
}

/*
** After it, we check that the 2 heap are balanced. If not we do a transfer from one
** heap to the other.
*/

void	rebalance_the_heaps(t_heap *heap_inf, t_heap *heap_sup)
{
	int size_difference;
	int number_to_swap;

	size_difference = heap_inf->size - heap_sup->size;
	if (size_difference == 2)
	{
		number_to_swap = ft_pop_max_heap(heap_inf);
		ft_insert_heap_min(heap_sup, number_to_swap);
	}
	else if (size_difference == -2)
	{
		number_to_swap = ft_pop_min_heap(heap_sup);
		ft_insert_heap_max(heap_inf, number_to_swap);
	}
}

/*
** Here we have access at all time to the median of our data set. We just
** have to choose determine if it's in the top heap or heap inf. If the
** total number of numbers, x, is even, the median is the x/2 th element.
** Which is the max of the heap inf. If it is odd, it is the max or min
** element in the biggest heap.  
*/

int		get_median_of_the_two_heaps(t_heap *heap_inf, t_heap *heap_sup)
{
	int total_elem;

	total_elem = heap_inf->size + heap_sup->size;
	if (total_elem % 2 == 0)
		return (heap_inf->array[1]);
	else if (heap_sup->size > heap_inf->size)
		return (heap_sup->array[1]);
	else
		return (heap_inf->array[1]);
}	

/*
** The goal of this exercise is to determine the median of a dataset 
** in a logarithmic time 0(logn), instead of a linear time O(n). To
** do so, we used two heaps, one min and one max. Be carefull the heap min
** is called heap_sup and the heap max is called heap_inf.
*/ 

int		main(int ac, char **av)
{
	t_heap	*heap_sup;
	t_heap	*heap_inf;
	char	*line;
	int 	fd;
	int		number;
	int	median;

	if (ac != 2)
		return (1);
	(void)av;
	heap_sup = malloc_heap(10002);
	heap_inf = malloc_heap(10002);
	if (!heap_sup || !heap_inf)
		return (1);
	fd = open(av[1], O_RDONLY);
	median = 0;
	while (get_next_line(fd, &line) > 0)
	{
		number = atoi(line);
		add_numb_in_one_of_the_two_heaps(heap_inf, heap_sup, number);
		rebalance_the_heaps(heap_inf, heap_sup)
		median += get_median_of_the_two_heaps(heap_inf, heap_sup);
		free(line);
	}
	free(line);
	ft_putnbr(median % 10000);
	free_heap(heap_sup);
	free_heap(heap_inf);
	return (0);
}
