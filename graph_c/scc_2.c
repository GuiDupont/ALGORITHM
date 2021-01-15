#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../libft/includes/libft.h"

int g_time = 1;

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

void	DFS_time_labelling(int **vertices, char *visited, int vertice, int *order)
{
	int i;

	i = 0;
	visited[vertice] = '1';
	while (vertices[vertice][i] != -1)
	{
		if (!visited[vertices[vertice][i]])
			DFS_time_labelling(vertices, visited, vertices[vertice][i], order);
		i++;
	}
	order[vertice] = g_time;
	g_time = g_time + 1;
	return ;
}


void	DFS(int **vertices, char *visited, int vertice)
{
	int i;

	i = 0;
	visited[vertice] = '1';
	ft_putnbr(vertice);
	ft_putchar(' ');
	while (vertices[vertice][i] != -1)
	{
		if (!visited[vertices[vertice][i]])
			DFS(vertices, visited, vertices[vertice][i]);
		i++;
	}
	return ;
}

int		**change_label_graph(int **graph, int *ref)
{
	int i;
	int y;
	int **new_graph;

	i = 1;
	if (!(new_graph = malloc(sizeof(*new_graph) * 875715)))
		return (0);
	while (i < 9)
	{
		y = 0;
		while (graph[i][y] != -1)
		{
			graph[i][y] = ref[graph[i][y]];
			y++;
		}
		new_graph[ref[i]] = graph[i];
		i++;
	}
	return (new_graph);
}

void	DFS_SCC(int **vertices, char *visited, int vertice, int *size)
{
	int i;

	i = 0;
	visited[vertice] = 0;
	*size = *size + 1;
	while (vertices[vertice][i] != -1)
	{
		if (visited[vertices[vertice][i]])
			DFS_SCC(vertices, visited, vertices[vertice][i], size);
		i++;
	}
	return ;
}

void	DFS_loop(int **graph, char *not_visited)
{
	int i;
	int size;

	i = 9;
	while (i > 0)
	{
		if (not_visited[i] == 1)
		{
			size = 0;
			DFS_SCC(graph, not_visited, i, &size);
			ft_putnbr(size);
			ft_putchar(' ');
		}
		i--;
	}
}

int main(void)
{
	int **normal_graph;
	int **reverse_graph;
	int **time_label_graph;
	int i;
	int fd;
	char *visited;
	int time;
	int *order;
	char *not_visited;

	if (!(normal_graph = malloc(sizeof(*normal_graph) * 875715)))
		return (0);
	if (!(reverse_graph = malloc(sizeof(*normal_graph) * 875715)))
		return (0);
	if (!(visited = malloc(sizeof(*visited) * 875715)))
		return (0);
	i = 0;
	while (i < 875715)
	{
		normal_graph[i] = malloc(sizeof(int) * 2);
		normal_graph[i][0] = -1;
		reverse_graph[i] = malloc(sizeof(int) * 2);
		reverse_graph[i][0] = -1;
		visited[i] = '\0';
		i++;
	}
	if (!(order = malloc(sizeof(*order) * 875715)))
		return (0);
	fd = open("scc_short.txt", O_RDONLY);
	if (fd < 0)
		return (fd);
	file_to_graph(fd, normal_graph, 0);
	close(fd);
	fd = open("scc_short.txt", O_RDONLY);
	if (fd < 0)
		return (fd);	
	file_to_graph(fd, reverse_graph, 1);
	close(fd);
	i = 9;
	while (i > 0)
	{
		if (visited[i] == '\0')
			DFS_time_labelling(reverse_graph, visited, i, order);
		i--;
	}
	time_label_graph = change_label_graph(normal_graph, order);
	//free(order);
	//here visited char* is set to one for every instance;
	not_visited = visited;
	DFS_loop(time_label_graph, not_visited);
	//DFS(normal_graph, visited, 9);
	i = 0;
	ft_putchar('\n');
	while (i < 875715)
	{
		// if (i && i < 10)
		// {
		// 	ft_putnbr(order[i]);
		// 	ft_putchar(' ');
		// }
		free(reverse_graph[i]);
		free(normal_graph[i++]);
	}
	free(reverse_graph);
	free(normal_graph);
	free(order);
}