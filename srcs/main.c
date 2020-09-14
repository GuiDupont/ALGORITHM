#include "../includes/algo.h"

int main (int ac, char **av)
{
	int *array;
	int	nb_elem;

	(void)ac;
	if (ac != 2)
		return (0);
	nb_elem = ft_atoi(av[1]);
	srand(time (NULL));
	if (!(array = malloc(sizeof(*array) * nb_elem)))
		return (0);
	randomize_array(array, nb_elem, nb_elem);
	print_array(array, nb_elem);
	ft_putstr("\nstarting sorting\n");
	ft_quicksort(array, 0, nb_elem);
	ft_putstr("done\n");
	print_array(array, nb_elem);
	array = NULL;
	free(array);
	return (0);
}
