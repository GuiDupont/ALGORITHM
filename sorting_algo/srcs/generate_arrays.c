#include "../includes/algo.h"

int		***create_arrays(int ***array, int nb_lines, int size_line)
{
	int i;

	i = 0;
	if (!(*array = malloc(sizeof(**array) * nb_lines)))
		return NULL;
	while (i < nb_lines)
	{
		if (!(array[0][i] = malloc(sizeof(***array) * (size_line))))
			return NULL;
		i++;
	}
	return array;
}

void	bzero_arrays(int **array, int nb_lines, int line_size)
{
	int i;
	int y;

	i = 0;
	while (i < nb_lines)
	{

		y = 0;
		while (y < line_size)
		{
			array[i][y] = 0;
			y++;
		}
		i++;
	}
}

void	randomize_array(int *array, int line_size, int max_value)
{
	int i;

	i = 0;

	while (i < line_size)
	{
		array[i] = rand() % max_value;
		i++;
	}
}

void	put_txt_in_array(int *array, int size, int fd)
{
	int		i = 0;
	char	*line;

	while (get_next_line(fd, &line) > 0 && i < size)
	{
		array[i] = ft_atoi(line);
		free(line);
		i++;
	}
}

void	randomize_arrays(int **array, int nb_lines, int line_size, int max_value)
{
	int i;

	i = 0;
	while (i < nb_lines)
	{
		randomize_array(array[i], line_size, max_value);
		i++;
	}
}
