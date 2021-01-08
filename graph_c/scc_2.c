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

void	file_to_graph(int fd, int *vertices[875715])
{
	char		*line;
	char		**nodes;
	int			i;
	int			*temp;
	int			node1;
	int			node2;
	int			ret;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!line || !line[0])
			return (free(line));
		node1 = atoi(strtok(line, " "));
		node2 = atoi(strtok(NULL, " "));
		free(line);
		if (node1 != node2)
		{
			i = 0;
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

void	DFS(int *vertices[875715], char visited[875715], int vertice)
{
	int i;

	i = 0;
	visited[vertice] = 1;
	printf("%d\n", vertice);
	while(vertices[vertice][i] != -1)
	{
		if (!visited[vertices[vertice][i]])
			DFS(vertices, visited, vertices[vertice][i]);
		i++;
	}
	return ;
}

int main(void)
{
	int *vertices[875715];
	int i = 0;
	int fd;
	char visited[875715];
	int *stack;

	while (i < 875715)
	{
		vertices[i] = malloc(sizeof(int) * 2);
		vertices[i][0] = -1;
		visited[i] = '\0';
		i++;
	}
	i = 0;
	fd = open("scc_short.txt", O_RDONLY);
	if (fd < 0)
		return (fd);
	file_to_graph(fd, vertices);
	close(fd);
	DFS(vertices, visited, 1);
	i = 0;
	while (i < 875715)
	{
		free(vertices[i++]);
	}
}