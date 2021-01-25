#include "../includes/heap.h"

t_heap	*malloc_heap(int futur_max_size)
{
	t_heap	*final;

	if (!(final = malloc(sizeof(*final))))
		return (NULL);
	if (!(final->array = malloc(sizeof(int) * futur_max_size)))
		return (NULL);
	final->size = 0;
	return (final);
}

void	free_heap(t_heap *to_free)
{
	free(to_free->array);
	free(to_free);
}

void	ft_print_max_heap(t_heap *heap)
{
	int i;

	i = 0;
	ft_printf("nb d'elem to print %d \n", heap->size);
	while (i < heap->size)
	{
		ft_printf("%d ; ", ft_pop_max_heap(heap));
		i++;
	}
	ft_putchar('\n');
}

void	ft_print_min_heap(t_heap *heap)
{
	int i;

	i = 0;
	ft_printf("nb d'elem to print %d \n", heap->size);
	while (i < heap->size)
	{
		ft_printf(" %d ; ", ft_pop_min_heap(heap));
		i++;
	}
	ft_putchar('\n');
}
