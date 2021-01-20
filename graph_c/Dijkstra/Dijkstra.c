#include <math.h>
#include <stdlib.h>


typedef	struct	s_vertex
{
	int *adjacent;
	int nb_adjacent;
	int *weight;
}
				t_vertex;

// void	dijkstra(t_graph *graph)


void	malloc_all(t_vertex **vertices, char **visited, int **distance_to_origin, int size)
{
	if (!(*vertices = malloc(sizeof(**vertices) * size)))
		return ;
	if (!(*visited = malloc(sizeof(**visited) * size)))
		return ;
	if (!(*distance_to_origin = malloc(sizeof(**distance_to_origin) * size)))
		return ;
	size--;
	while (size >= 0)
	{
		visited[0][size] = '\0';
		distance_to_origin[0][size] = INFINITY;
		vertices[0][size].nb_adjacent = 0;
		vertices[0][size].adjacent = NULL;
		vertices[0][size].weight = NULL;
		size--;
	}
}

void	add_vertex(int to_add, int vertex_target, t_vertex *vertices)
{
	int *new;

	if (!(new = malloc(sizeof(*new) * (vertices[vertex_target].nb_adjacent + 1))))
		return ;
	if (vertices[vertex_target].adjacent)
		ft_arraycpy(new, vertices[vertex_target].adjacent);
	new[vertices[vertex_target].nb_adjacent] = to_add;
	vertices[vertex_target].nb_adjacent += 1;
	free(vertices[vertex_target].adjacent);
	vertices[vertex_target].adjacent = new;
}

void	file_to_graph(int fd, t_vertex *vertices, int reverse)
{
	char		*line;
	char		**line_divide;
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
		line_divide = ft_split(line, ' ');
		node1 =  atoi(line_divide[0]);
		i = 1;
		while (line_divide[i])
		{
			add_vertex(atoi(line_divide[i]), node1, vertices));
			add_edge_weight(atoi(ft_strchr(line_divide[i], ',') + 1), node1, vertices);
		}
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

int	main(int ac, char **av)
{
	char *visited;
	int	*distance_to_origin;
	t_vertex *vertices;

	if (ac == 1)
		return (1);
	malloc_all(&vertices, &visited, &distance_to_origin, 201);

	//dijkstra(graph);
	return (0);
}