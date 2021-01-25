#include "../../includes/libft.h"

void	ft_put_txt_in_array(int *array, int size, int fd)
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
