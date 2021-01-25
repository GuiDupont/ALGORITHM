#include "../../includes/libft.h"

void	ft_randomize_array(int *array, int line_size, int max_value)
{
	int i;

	i = 0;

	while (i < line_size)
	{
		array[i] = rand() % max_value;
		i++;
	}
}
