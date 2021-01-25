#include "../../includes/libft.h"

void	ft_insertionsort(int *array, int nb_elem)
{
	int i;
	int y;

	i = 1;
	if (!array)
		return ;
	while(i < nb_elem)
	{
		y = i;
		while (y - 1 >= 0)
		{

			if (array[y - 1] > array[y])
			{
				ft_swap(&array[y - 1], &array[y]);
				y--;
			}
			else
				break;
		}
		i++;
	}
}