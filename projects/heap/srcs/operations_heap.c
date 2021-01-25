#include "../includes/heap.h"

void	ft_insert_heap_max(t_heap *heap, int number)
{
	int *array;
	int i;

	if (!heap)
		return ;
	array = heap->array;
	(heap->size)++;
	array[heap->size] = number;
	i = heap->size;
	while (i > 0 && array[i / 2] < array[i])
	{
		ft_swap(&array[i / 2], &array[i]);
		i /= 2;
	}
}

void	ft_insert_heap_min(t_heap *heap, int number)
{
	int *array;
	int i;

	if (!heap)
		return ;
	array = heap->array;
	(heap->size)++;
	array[heap->size] = number;
	i = heap->size;
	while (i > 0 && array[i / 2] > array[i])
	{
		ft_swap(&array[i / 2], &array[i]);
		i /= 2;
	}
}

int		ft_pop_min_heap(t_heap *heap)
{
	int *array;
	int i;
	int	poped;

	if (!heap)
		return (0);
	array = heap->array;
	ft_putstr("salut\n");
	ft_swap(&array[1], &array[heap->size]);
	ft_putstr("coucou\n");
	poped = array[heap->size];
	heap->size -= 1;
	i = 1;
	ft_putstr("test\n");
	while (i < heap->size && (array[i * 2] < array[i] || array[i * 2 + 1] < array[i]))
	{
		if (array[i * 2] < array[i * 2 + 1])
		{
			ft_swap(&array[i], &array[i * 2]);
			i *= 2;
		}
		else
		{
			ft_swap(&array[i], &array[i * 2 + 1]);
			i = 2 * i + 1;
		}
	}
	return (poped);
}

void	ft_pop_max_heap(t_heap *heap)
{
	int *array;
	int i;

	if (!heap)
		return ;
	array = heap->array;
	ft_swap(&array[1], &array[heap->size]);
	heap->size -= 1;
	i = 1;
	while (i < heap->size && (array[i * 2] > array[i] || array[i * 2 + 1] > array[i]))
	{
		if (array[i * 2] > array[i * 2 + 1])
		{
			ft_swap(&array[i], &array[i * 2]);
			i *= 2;
		}
		else
		{
			ft_swap(&array[i], &array[i * 2 + 1]);
			i = 2 * i + 1;
		}
	}
}
