#include "../includes/algo.h"

int		*count_occurences(int *array, int size, int max_value)
{
	int i;
	int *count;

	i = 0;
	if (!(count = malloc(sizeof(*count) * max_value)))
		return (0);
	ft_bzero(count, max_value);
	while (i < size)
	{
		count[array[i]] += 1;
		i++;
	}
	return (count);
}
