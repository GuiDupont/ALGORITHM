#include "graph.h"

void	print_n_first_vertices(t_graph *graph, int n)
{
	t_vertices *vertex = &(graph->vertices);

	while (n > 0 && vertex)
	{
		printf("vertex->id = %d ", vertex->id);
		vertex = vertex->next;
		n--;
	}
	ft_putchar('\n');
}

int	ft_nb_edges(t_edges *edges)
{
	int i = 0;

	while (edges)
	{
		edges = edges->next;
		i++;
	}
	return (i);
}

int	ft_nb_vertices(t_vertices *vertex)
{
	int i = 0;

	while (vertex)
	{
		vertex = vertex->next;
		i++;
	}
	return (i);
}


t_edges *create_new_edge(int vertex1, int vertex2)
{
	t_edges *edges;

	if (!(edges = malloc(sizeof(*edges))))
		return (NULL);
	edges->next = NULL;
	edges->vertices[0] = vertex1;
	edges->vertices[1] = vertex2;
	return (edges);
}

int		check_if_edge_exists(int vertex1, int vertex2, t_edges *edges)
{
	while (edges)
	{
		if ((edges->vertices[0] == vertex1 && edges->vertices[1] == vertex2) ||
		(edges->vertices[0] == vertex2 && edges->vertices[1] == vertex1))
			return (1);
		edges = edges->next;
	}
	return (0);
}

void	set_up_vertices(char *line, t_vertices *vertices)
{
	char		**line_2d;
	int			i;

	if (!(vertices->next = malloc(sizeof(*vertices))))
			return ;
	vertices->next->next = NULL;
	line_2d = ft_split(line, '\t');
	vertices->next->id = atoi(line_2d[0]);
	i = 1;
	while (line_2d[i])
	{
		vertices->next->adjacent_v[i - 1] = atoi(line_2d[i]);
		i++;
	}
	vertices->next->adjacent_v[i - 2] = -1;
	//vertices = vertices->next;
	free(line);
	ft_free_split(line_2d);
}

void	graph_vertices_to_edges(t_graph *graph)
{
	t_vertices	*vertices;
	t_edges		*edges;
	int i;
	
	vertices = graph->vertices.next; // now we have to set up our edges using our vertices
	edges = &(graph->edges);
	while (vertices)
	{
		i = 1;
		while (vertices->adjacent_v[i] != -1)
		{
			if (!check_if_edge_exists(vertices->id, vertices->adjacent_v[i], graph->edges.next))
			{
				edges->next = create_new_edge(vertices->id, vertices->adjacent_v[i]);
				edges = edges->next;
			}
			i++;
		}

		vertices = vertices->next;
	}
}


void	change_all_edges_rmv_self_loop(int vertex1, int vertex2, t_graph *graph)
{
	t_edges *previous = &(graph->edges);
	t_edges *edge = graph->edges.next;

	while (edge)
	{
		if (edge->vertices[0] == vertex1)
			edge->vertices[0] = vertex2;
		else if (edge->vertices[1] == vertex1)
			edge->vertices[1] = vertex2;
		if (edge->vertices[0] == edge->vertices[1])
		{
			//printf("edge_vertices :%d %d\n", edge->vertices[0], edge->vertices[1]);
			previous->next = edge->next;
			free(edge);
			edge = previous->next;
		}
		else
		{
			edge = edge->next;
			previous = previous->next;
		}
	}
}

void	rmv_vertex(int vertex_id, t_graph *graph)
{
	t_vertices *previous = &(graph->vertices);
	t_vertices *vertices = graph->vertices.next;

	while (vertices)
	{
		if (vertices->id == vertex_id)
		{
			previous->next = vertices->next;
			free(vertices);
			vertices = previous->next;
		}
		else
		{
			vertices = vertices->next;
			previous = previous->next;
		}
	}
	
}

void	delete_one_edge(t_graph *graph)
{
	int edge_chosen;
	int nb_edges;
	int vertex_id;
	int i;
	t_edges *edges;

	nb_edges = ft_nb_edges(graph->edges.next);
	edge_chosen = rand() % nb_edges;
	//printf("nb_edges = %d and edges_chosen: %d\n", nb_edges, edge_chosen);
	edge_chosen++;
	edges = graph->edges.next;
	i = 1;
	while (i < edge_chosen)
	{
		edges = edges->next;
		i++;
	}

	vertex_id = edges->vertices[0];
	change_all_edges_rmv_self_loop(edges->vertices[0], edges->vertices[1], graph);
	rmv_vertex(vertex_id, graph);
}

void	free_graph(t_graph *graph)
{
	t_vertices	*vertices;
	t_edges		*edges;
	t_vertices	*next_vertex;
	t_edges		*next_edge;

	edges = graph->edges.next;
	vertices = graph->vertices.next;
	while (edges)
	{
		next_edge = edges->next;
		free(edges);
		edges = next_edge;
	}
	while (vertices)
	{
		next_vertex = vertices->next;
		free(vertices);
		vertices = next_vertex;
	}
}

void	file_to_graph(int fd, t_graph *graph)
{
	char		*line;
	t_vertices	*vertices;
	int			i;

	vertices = &(graph->vertices);
	while (get_next_line(fd, &line) > 0) //here we set up all our vertices
	{
		set_up_vertices(line, vertices);
		vertices = vertices->next;
	}
	free(line);
	graph_vertices_to_edges(graph);
}

int	main(int ac, char **av)
{
	t_graph graph;
	t_vertices *vertex;
	t_edges *edges;
	int fd = open("graph.txt", O_RDONLY);
	int edge_chosen;
	int nb_vertices;
	int i = 0;
	int min = 40000;
	
	if (fd < 0)
		return (0);
	srand(time (NULL));
	while (i < 40000)
	{
		graph.vertices.id = -1;
		graph.vertices.next = NULL;
		graph.edges.next = NULL;
		fd = open("graph.txt", O_RDONLY);
		file_to_graph(fd, &graph);
		close(fd);
		vertex = graph.vertices.next;
		while(ft_nb_vertices(graph.vertices.next) > 2)
		{
			delete_one_edge(&graph);
		}
		vertex = graph.vertices.next;
		if (ft_nb_edges(graph.edges.next) < min)
		{
			min = ft_nb_edges(graph.edges.next);
			printf("new min = %d\n", min);
		}
		free_graph(&graph);
		if (i % 20 == 0)
			printf("%d\n", i);
		i++;
	}
	return (0);
}