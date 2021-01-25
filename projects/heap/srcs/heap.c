#include "../includes/heap.h"

// void	add_numb_in_one_of_the_two_heaps(t_heap *heap_min, t_heap *heap_max, int to_add)
// {
// 	if (heap_min->size == 1 || to_add < )	
// }

int main(int ac, char **av)
{
	t_heap	*heap_max;
	t_heap	*heap_min;
	char	*line;
	int 	fd;
	int		to_add;
	int 	i;

	if (ac != 2)
		return (1);
	heap_max = malloc_heap(5002);
	heap_min = malloc_heap(10002);
	if (!heap_max || !heap_min)
		return (1);
	fd = open(av[1], O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		to_add = atoi(line);
		ft_insert_heap_min(heap_min, to_add);
		//add_numb_in_one_of_the_two_heaps(heap_min, heap_max, to_add)
		free(line);
		i++;
	}
	ft_putnbr(heap_min->size);
	i = 10000;
	while (i > 0)
	{
		printf("%d ", ft_pop_min_heap(heap_min));
		i--;
	}
	return (0);
}
