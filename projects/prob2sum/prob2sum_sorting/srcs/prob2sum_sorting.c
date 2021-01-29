#include "../includes/prob2sum_sorting.h"

int	main(int ac, char **av)
{
	int fd;
	long long *array;
	char *line;
	int i = 0;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (fd);
	if (!(array = malloc(sizeof(*array) * 1000001)))
		return (-1);
	while (get_next_line(fd, &line) > 0)
		array[i++] = ft_atoll(line);
	ft_quicksort_ll(array, 1000001);
	while (i > 0)
	{
		if (array[i] < 0)
			printf("%lld ", array[i]);
		i--;
	}
}