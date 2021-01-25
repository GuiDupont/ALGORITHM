#include "../includes/heap.h"

void	add_numb_in_one_of_the_two_heaps(t_heap *heap_inf, t_heap *heap_sup, int number)
{
	// int size_difference;
	// int number_to_swap;

	if (heap_inf->size == 0 || number < heap_inf->array[1])
	{
		ft_printf("new to add : %d\n", number);
		ft_insert_heap_max(heap_inf, number);
	}
	else
	{
		ft_printf("new to add : %d\n", number);
		ft_insert_heap_min(heap_sup, number);
	
	}
	// size_difference = heap_inf->size - heap_sup->size;
	// if (size_difference == 2)
	// {
	// 	number_to_swap = ft_pop_max_heap(heap_inf);
	// 	ft_insert_heap_min(heap_sup, number_to_swap);
	// }
	// else if (size_difference == -2)
	// {
	// 	number_to_swap = ft_pop_min_heap(heap_sup);
	// 	ft_insert_heap_max(heap_inf, number_to_swap);
	// }
}

int main(int ac, char **av)
{
	t_heap	*heap_sup;
	t_heap	*heap_inf;
	char	*line;
	int 	fd;
	int		number;

	if (ac != 2)
		return (1);
	heap_sup = malloc_heap(10002);
	heap_inf = malloc_heap(10002);
	if (!heap_sup || !heap_inf)
		return (1);
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		number = atoi(line);
		//add_numb_in_one_of_the_two_heaps(heap_sup, heap_inf, number);
		ft_insert_heap_max(heap_inf, number);
		free(line);
	}
	free(line);
	//ft_print_array(heap_sup->array, heap_sup->size + 1);
	//ft_print_array(heap_inf->array, heap_inf->size + 1);
	ft_print_max_heap(heap_inf);
	//ft_print_min_heap(heap_sup);
	free_heap(heap_sup);
	free_heap(heap_inf);
	return (0);
}
