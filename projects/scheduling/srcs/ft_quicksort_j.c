#include "../includes/scheduling.h"

void	ft_swap_j(t_jobs **a, t_jobs **b)
{
	t_jobs *c;

	c = *a;
	*a = *b;
	*b = c;
}

// static int		*find_mediane(int *a, int *b, int *c)
// {
// 	if ((*a <= *c && *a >= *b) || (*a >= *c && *a <= *b))
// 		return (a);
// 	else if ((*b <= *c && *b >= *a) || (*b >= *c && *b <= *a))
// 		return (b);
// 	else
// 		return (c);
// }

static int partition_2_j(t_jobs **array, int size)
{
	int sup = 1;
	int inf = 0;
	int i = 1;
	int middle;

	middle = size / 2;
	if (size % 2 == 0)
		middle--;
	//ft_swap(&array[0], find_mediane(&array[0], &array[size - 1], &array[middle]));
	while (i < size)
	{
		if (array[i]->ratio > array[0]->ratio)
			sup++;
		if (array[i]->ratio < array[0]->ratio)
		{
			ft_swap_j(&array[i], &array[inf + 1]);
			sup++;
			inf++;
		}
		i++;
	}
	ft_swap_j(&array[0], &array[inf]);
	return (inf);
}

static int		ft_quicksort_2_j(t_jobs **array, int size)
{
	int pivot;
	int size_right;
	int nb_comp;

	if (size < 1)
		return (0);
	nb_comp = size - 1;
	pivot = partition_2_j(array, size);
	size_right = size - pivot - 1;
	nb_comp += ft_quicksort_2_j(&array[pivot + 1], size_right);
	nb_comp += ft_quicksort_2_j(&array[0], pivot);
	return (nb_comp);
}

void	ft_quicksort_j(t_jobs **array, int size)
{
	//int total_comp;

	//total_comp = ft_quicksort_2(array, size);
	ft_quicksort_2_j(array, size);
}