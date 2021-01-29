#include "../../includes/libft.h"

long long	*find_mediane(long long *a, long long *b, long long *c)
{
	if ((*a <= *c && *a >= *b) || (*a >= *c && *a <= *b))
		return (a);
	else if ((*b <= *c && *b >= *a) || (*b >= *c && *b <= *a))
		return (b);
	else
		return (c);
}

static int partition(long long *array, int size)
{
	int sup = 1;
	int inf = 0;
	int i = 1;
	int middle;

	middle = size / 2;
	if (size % 2 == 0)
		middle--;
	ft_swap_ll(&array[0], find_mediane(&array[0], &array[size - 1], &array[middle]));
	while (i < size)
	{
		if (array[i] > array[0])
			sup++;
		if (array[i] < array[0])
		{
			ft_swap_ll(&array[i], &array[inf + 1]);
			sup++;
			inf++;
		}
		i++;
	}
	ft_swap_ll(&array[0], &array[inf]);
	return (inf);
}

long long	ft_quicksort_ll(long long *array, int size)
{
	long long pivot;
	int size_right;
	int nb_comp;

	if (size < 1)
		return (0);
	nb_comp = size - 1;
	pivot = partition(array, size);
	size_right = size - pivot - 1;
	nb_comp += ft_quicksort_ll(&array[pivot + 1], size_right);
	nb_comp += ft_quicksort_ll(&array[0], pivot);
	return (nb_comp);
}
