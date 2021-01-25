#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../libft/includes/libft.h"

void	ft_arraycpy(int *dst, int *src)
{
	int i;

	i = 0;
	while (src[i] != -1)
	{
		dst[i] = src[i];
		i++;
	}
}

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	file_to_graph(int fd, int **vertices, int reverse)
{
	char		*line;
	char		**nodes;
	int			i;
	int			*temp;
	int			node1;
	int			node2;
	int			ret;
	char		**node;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!line || !line[0])
			return (free(line));
		node = ft_split(line, ' ');
		if (node[0])
			node1 = atoi(node[0]);
		else
			node1 = 0;
		if (node[1])
			node2 = atoi(node[1]);
		else
			node2= 0;
		ft_free_split(node);
		free(line);
		if (node1 != node2 && node2 && node1)
		{
			i = 0;
			if (reverse)
				ft_swap(&node1, &node2);
			while (vertices[node1][i] != -1)
				i++;
			temp = malloc(sizeof(int) * (i + 2));
			ft_arraycpy(temp, vertices[node1]);
			temp[i] = node2;
			temp[i + 1] = -1;
			free(vertices[node1]);
			vertices[node1] = temp;
		}
	}
	free(line);
}
