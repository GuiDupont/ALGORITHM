#include "../includes/algo.h"


void	ft_arraycpy(int *dst, int *src, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

void	fusion_sort(int *array, int size)
{
	int	*sub_array1;
	int	*sub_array2;
	int	i = -1, j = 0, k = 0;

	if (size <= 1)
		return ;
	else if (size >= 3)
	{
		fusion_sort(array, size / 2);
		fusion_sort(array, size - (size / 2));
	}
	if (!(sub_array1 = malloc(sizeof(*sub_array1) * size / 2)))
		return ;
	if (!(sub_array2 = malloc(sizeof(*sub_array2) * (size - size / 2))))
		return ;
	ft_arraycpy(sub_array1, array, size / 2);
	ft_arraycpy(sub_array2, &array[size / 2], (size - size / 2));
	while (++i < size) 
	{
		if (sub_array1(j) <= sub_array2(k))
			array(i) = sub_array1(j++);
		else
			array(i) = sub_array2(k++);
	}
	free(sub_array1);
	free(sub_array2);
}

int main(int ac, char **av)
{
	(void)ac;
	int array[4] = ;

	fusion_sort(array, 4);
}