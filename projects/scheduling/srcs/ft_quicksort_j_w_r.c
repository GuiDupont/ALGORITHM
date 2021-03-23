#include "../includes/scheduling.h"

void	ft_insertionsort_j_w_d(t_jobs **array, int nb_elem)
{
	int i;
	int y;

	i = 1;
	if (!array)
		return ;
	while (i < nb_elem)
	{
		y = i;
		while (y - 1 >= 0)
		{
			if (array[y - 1]->w < array[y]->w)
			{
				ft_swap_j(&array[y - 1], &array[y]);
				y--;
			}
			else
				break;
		}
		i++;
	}
}
