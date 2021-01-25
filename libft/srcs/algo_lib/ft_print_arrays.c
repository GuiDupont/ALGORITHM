#include "../../includes/libft.h"

void	ft_print_arrays(int **arrays, int nb_lines, int line_size)
{
	int i;

	i = 0;
	while (i < nb_lines)
	{
		print_array(arrays[i], line_size);
		i++;
	}
}
