
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


void	ft_arraycpy(int *dst, int *src, int len);
int 	get_next_line(int fd, char **line);
int		ft_atoi(char *s);

double	merge_sort_count(int *array, int size)
{
	int	*sub_array1;
	int	*sub_array2;
	int	i = -1, j = 0, k = 0;
	double	current_inv = 0, left_inv = 0, right_inv = 0;

	if (size <= 1)
		return (0);
	if (size > 2)
	{
		left_inv = merge_sort_count(array, size / 2);
		right_inv = merge_sort_count(&array[size / 2], size - (size / 2));
	}
	if (!(sub_array1 = malloc(sizeof(*sub_array1) * size / 2)))
	 	return (0);
	ft_arraycpy(sub_array1, array, size / 2);
	if (!(sub_array2 = malloc(sizeof(*sub_array2) * (size - size / 2))))
	 	return (0);
	ft_arraycpy(sub_array2, &array[size / 2], (size - size / 2));
	while (++i < size && j + k != size) 
	{
		if (j == size / 2)
			array[i] = sub_array2[k++];
		else if (sub_array1[j] <= sub_array2[k] || k == size - size / 2)
			array[i] = sub_array1[j++];
		else
		{
			array[i] = sub_array2[k++];
			current_inv += size / 2;
			current_inv -= j;
		}
	}
	free(sub_array1);
 	free(sub_array2);
	//printf("current_inv = %d\n", current_inv);
	return (current_inv + left_inv + right_inv);
}


int main(void)
{
	int test[8] = {1, 10, 7, 3, 8, 2, 4, 6};
	int test2[6] = {1, 6, 5, 3, 4, 2};
	int *test3 = malloc(100000 * sizeof(int));
	int i = 0;
	char *line;
	int fd;

	fd = open("array.txt", O_RDONLY);

	while (i < 100000)
	{
		get_next_line(fd, &line);
		test3[i] = ft_atoi(line);
		free(line);
		i++;
	}
	printf("nb of inversion %f", merge_sort_count(test3,100000));
	return (0);
}