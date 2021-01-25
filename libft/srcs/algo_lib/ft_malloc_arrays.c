#include "../../includes/libft.h"

int		***ft_malloc_arrays(int ***array, int nb_lines, int size_line)
{
	int i;

	i = 0;
	if (!(*array = malloc(sizeof(**array) * nb_lines)))
		return NULL;
	while (i < nb_lines)
	{
		if (!(array[0][i] = malloc(sizeof(***array) * (size_line))))
			return NULL;
		i++;
	}
	return array;
}
