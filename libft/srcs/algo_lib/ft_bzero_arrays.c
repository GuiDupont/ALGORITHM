#include "../../includes/libft.h"

void	ft_bzero_arrays(int **array, int nb_lines, int line_size)
{
	int i;
	int y;

	i = 0;
	while (i < nb_lines)
	{

		y = 0;
		while (y < line_size)
		{
			array[i][y] = 0;
			y++;
		}
		i++;
	}
}
