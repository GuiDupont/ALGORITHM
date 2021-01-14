#include "stdlib.h"
#include "stdio.h"
#include "libft/libft.h"

int	*init_UF(unsigned int n)
{
	int *array;

	if (!(array = malloc(sizeof(*array) * n)))
		return (NULL);
	while (n--)
		array[n] = n;
	return (array);
}

int	*init_UF_SIZE(unsigned int n)
{
	int *array;

	if (!(array = malloc(sizeof(*array) * n)))
		return (NULL);
	while (n--)
		array[n] = 1;
	return (array);
}
void	print_array(int *array, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(array[i]);
		(i != size - 1) ? ft_putstr(", ") : ft_putchar('\n');
		i++;
	}
}

int		root_UF(int *array, int i)
{
	while (array[i] != i)
	{
	array[i] = array[array[i]];
		i = array[i];
	}
	return (i);
}

void	union_UF(int *size ,int *array, unsigned int n, unsigned int n2)
{
	int i = root_UF(array, n);
	int j = root_UF(array, n2);
	if (i == j)
		return ;
	if (size[i] <= size[j])
	{
		array[i] = j;
		size[j] += size[i];
	}
	else
	{
		array[j] = i;
		size[i] += size[j];
	}
}

int		find_UF(int *array, unsigned int n, unsigned int n2)
{
	return (root_UF(array, n) == root_UF(array, n2));
}

int main(void)
{
	int n = 13;
	int *array;
	int *size;

	array = init_UF(n);
	size = init_UF_SIZE(n);
	print_array(array, n);
	print_array(size, n);
	union_UF(size, array, 11, 9);
	union_UF(size, array, 12, 9);
	union_UF(size, array, 9, 6);
	union_UF(size, array, 10, 8);
	union_UF(size, array, 6, 8);
	union_UF(size, array, 6, 3);
	union_UF(size, array, 7, 3);
	union_UF(size, array, 4, 1);
	print_array(array, n);


}