#include "algo.h"

void	print_array(int *array, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(array[i]);
		(i != size - 1) ? ft_putstr(", ") : ft_putchar('\0');
		i++;
	}
}

void	print_arrays(int **arrays, int nb_lines, int line_size)
{
	int i;

	i = 0;
	while (i < nb_lines)
	{
		print_array(arrays[i], line_size);
		(i != nb_lines- 1) ?ft_putchar('\n') : ft_putchar('\0');
		i++;
	}
}

