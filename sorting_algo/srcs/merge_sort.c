#include "../includes/algo.h"

void	merge_sort(int *array, int size)
{
	int	*sub_array1;
	int	*sub_array2;
	int	i = -1, j = 0, k = 0;

	if (size <= 1)
		return ;
	if (size > 2)
	{
		merge_sort(array, size / 2);
		merge_sort(&array[size / 2], size - (size / 2));
	}
	if (!(sub_array1 = malloc(sizeof(*sub_array1) * size / 2)))
	 	return ;
	ft_arraycpy(sub_array1, array, size / 2);
	if (!(sub_array2 = malloc(sizeof(*sub_array2) * (size - size / 2))))
	 	return ;
	ft_arraycpy(sub_array2, &array[size / 2], (size - size / 2));
	while (++i < size && j + k != size) 
	 {
		if (j == size / 2)
			array[i] = sub_array2[k++];
		else if (sub_array1[j] <= sub_array2[k] || k == size - size / 2)
			array[i] = sub_array1[j++];
		else
			array[i] = sub_array2[k++];
	}
	free(sub_array1);
 	free(sub_array2);
}
