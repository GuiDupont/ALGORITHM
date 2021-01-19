#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../libft/includes/libft.h"

int g_time = 1;
void	file_to_graph(int fd, int **vertices, int reverse);
void	ft_swap(int *a, int *b);
void	ft_arraycpy(int *dst, int *src);

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
	while (i < 10)
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
	visited[vertice] = '\0';
	*size = *size + 1;
	while (vertices[vertice][i] != -1)
	{
		if (visited[vertices[vertice][i]] == '1')
			DFS_SCC(vertices, visited, vertices[vertice][i], size);
		i++;
	}
	return ;
}

void	DFS_loop(int **graph, char *not_visited)
{
	int i;
	int size;

	i = 875714;
	while (i > 0)
	{
		if (not_visited[i] == '1')
		{
			size = 0;
			DFS_SCC(graph, not_visited, i, &size);
			ft_putnbr(size);
			ft_putchar(' ');
		}
		i--;
	}
}


void	malloc_graphs(int ***normal_graph, int ***reverse_graph, char **visited, int **order)
{
	int i;

	if (!(*normal_graph = malloc(sizeof(**normal_graph) * 875715)))
		return ;
	if (!(*reverse_graph = malloc(sizeof(**normal_graph) * 875715)))
		return ;
	if (!(*visited = malloc(sizeof(**visited) * 875715)))
		return ;
	i = 0;
	while (i < 875715)
	{
		normal_graph[0][i] = malloc(sizeof(int) * 2);
		normal_graph[0][i][0] = -1;
		reverse_graph[0][i] = malloc(sizeof(int) * 2);
		reverse_graph[0][i][0] = -1;
		visited[0][i] = '\0';
		i++;
	}
	if (!(*order = malloc(sizeof(**order) * 875715)))
		return ;
}

void	set_both_graph(int **normal_graph, int **reverse_graph, char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	file_to_graph(fd, normal_graph, 0);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;	
	file_to_graph(fd, reverse_graph, 1);
	close(fd);
}


int		**time_labelling(int **reverse_graph, int **normal_graph, char *visited, int *order)
{
	int i;
	int **time_label_graph;

	i = 875714;
	while (i > 0)
	{
		if (visited[i] == '\0')
			DFS_time_labelling(reverse_graph, visited, i, order);
		i--;
	}
	time_label_graph = change_label_graph(normal_graph, order);
	return (time_label_graph);
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

	malloc_graphs(&normal_graph, & reverse_graph, &visited, &order);
	set_both_graph(normal_graph, reverse_graph, "graph.txt");
	time_label_graph = time_labelling(reverse_graph, normal_graph, visited, order);

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