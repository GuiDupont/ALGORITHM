#include "../includes/heap.h"

t_heap	*malloc_heap(int futur_max_size)
{
	t_heap	*final;

	if (!(final = malloc(sizeof(*final))))
		return (NULL);
	if (futur_max_size < 1)
		futur_max_size = 1;
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
