#include "algo.h"

int main (void)
{
	int *array;
	int	nb_elem;

	nb_elem = 10;
	srand(time (NULL));
	if (!(array = malloc(sizeof(*array) * nb_elem)))
		return (0);
	randomize_array(array, nb_elem, nb_elem);
	print_array(array, nb_elem);
	ft_putchar('\n');
	ft_quicksort(array, 0, nb_elem);
	print_array(array, nb_elem);
//	free(array);
	array = NULL;
	return (0);
}
