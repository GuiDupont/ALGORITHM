#include "../includes/algo.h"

static int	partition(int *array, int index_min, int size)
{
	int i;
	int y;

	if (index_min >= 0)
		i = index_min - 1;
	else
		i = -1;
	y = index_min;
	while (y < size - 1)
	{
		if (array[y] <= array[size - 1])
		{
			i++;
			ft_swap(&array[i], &array[y]);
		}
		y++;
	}
	i++;
	ft_swap(&array[size - 1], &array[i]);
	print_array(array, size);
	return (i);
}


void	ft_launcher(int *array, int index_min, int size)
{
	int i;

	i = partition(array, index_min, size);
	if ((size - (i + 1)) > 1)
		ft_launcher(array, i + 1, size);
	if (((1 + i) - index_min) > 1)
		ft_launcher(array, index_min, i);
}

void	ft_quicksort(int *array, int size)
{
	print_array(array, size);
	ft_launcher(array, 0, size);
	print_array(array, size);
}
