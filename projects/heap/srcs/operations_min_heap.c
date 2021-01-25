#include "../includes/heap.h"

/*
** This function add an element to the end of the heap. Then it progressively
** makes the new node swap with its parent node if value(parent) > value(child)
*/

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
	while (i > 1 && array[i] < array[i / 2])
	{
		ft_swap(&array[i / 2], &array[i]);
		i /= 2;
	}
}


/*
** The following function is used to know if one of child of a given node is bigger
** If it is not or doesn't exist we return 0. The to_add variable is used to distinguish
** left and right.
*/


static int ft_is_min_candidate(int i, t_heap *heap, int to_add)
{
	if (i * 2 + to_add > heap->size)
		return (0);
	if (heap->array[i * 2 + to_add] < heap->array[i])
		return (1);
	return (0);
}

/*
** Pop min heap withdraw the min value of the heap, which is at array[1].
** For these, we do a swap with the last element, then we swap our new
** top element til we can find a child that is smaller. If we find 2 smaller
** children, we do the swap with the smallest one.
** We nust be careful and check if the values (2 * i) and (2 * i + 1) are valid index
** These is done using ft_is_min_candidate.
*/

int		ft_pop_min_heap(t_heap *heap)
{
	int *array;
	int i;
	int	poped;
	int left_child;
	int right_child;

	if (!heap)
		return (0);
	array = heap->array;
	ft_swap(&array[1], &array[heap->size]);
	poped = array[heap->size];
	heap->size -= 1;
	i = 1;
	left_child = 0;
	right_child = 0;
	while (i < heap->size)
	{
		if (i * 2 > heap->size)
			return (poped);
		left_child = ft_is_min_candidate(i, heap, 0);
		right_child = ft_is_min_candidate(i, heap, 1);
		if (left_child == 1 && right_child == 0)
		{
			ft_swap(&array[i], &array[i * 2]);
			i *= 2;
		}
		else if (right_child == 1 && left_child == 0)
		{
			ft_swap(&array[i], &array[i * 2 + 1]);
			i = i * 2 + 1;
		}
		else if (right_child == 1 && left_child == 1)
		{
			if (heap->array[i * 2] < heap->array[i * 2 + 1])
			{
				ft_swap(&array[i], &array[i * 2]);
				i *= 2;
			}
			else
			{
				ft_swap(&array[i], &array[i * 2 + 1]);
				i = i * 2 + 1;
			}
		}
		else
			return (poped);
	}
	return (poped);
}
