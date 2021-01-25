#include "../../includes/libft.h"

void	ft_print_array(int *array, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(array[i]);
		(i != size - 1) ? ft_putstr(" ; ") : ft_putchar('\n');
		i++;
	}
}
