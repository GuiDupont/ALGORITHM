#include "algo.h"

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

int		partition(int *array, int low, int high)
{
	int i;
	int y;
	int ref;

	i = low - 1;
	y = 0;
	ref = array[high - 1];
	while (y < high - 2)
	{
		if (array[y] < ref)
		{
			i++;
			ft_swap(&array[i + 1], &array[i]);
		}
		y++;
	}
	ft_swap(&array[high - 1], &array[i + 1]);
	return (i + 1);
}


void	ft_quicksort(int *array, int low, int high)
{
	int i;

	i = partition(array, low, high);
	ft_quicksort(array, i + 1, high);
	ft_quicksort(array, low, i - 1);
}
