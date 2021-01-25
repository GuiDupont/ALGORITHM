#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../../libft/includes/libft.h"
#include <stdio.h>

typedef	struct	s_vertex
{
	int *adjacent;
	int nb_adjacent;
	int *weight;
	int	distance_to_origin;
}
				t_vertex;


int		one_node_not_visited(char *visited)
{
	int i;

	i = 0;
	while (visited[i])
	{
		if (visited[i] == '0')
			return (1);
		i++;
	}
	return (0);
}

void	malloc_all(t_vertex **vertices, char **visited, int size)
{
	if (!(*vertices = malloc(sizeof(**vertices) * size)))
		return ;
	if (!(*visited = malloc(sizeof(**visited) * size + 1)))
		return ;
	visited[0][size] = '\0';
	size--;
	while (size >= 0)
	{
		visited[0][size] = '0';
		vertices[0][size].distance_to_origin = 2147483647;
		vertices[0][size].nb_adjacent = 0;
		vertices[0][size].adjacent = NULL;
		vertices[0][size].weight = NULL;
		size--;
	}
	vertices[0][1].distance_to_origin = 0;
}

void	add_vertex(int to_add, int vertex_target, t_vertex *vertices)
{
	int *new;

	if (!(new = malloc(sizeof(*new) * (vertices[vertex_target].nb_adjacent + 1))))
		return ;
	if (vertices[vertex_target].adjacent)
		ft_arraycpy(new, vertices[vertex_target].adjacent, vertices[vertex_target].nb_adjacent);
	new[vertices[vertex_target].nb_adjacent] = to_add;
	free(vertices[vertex_target].adjacent);
	vertices[vertex_target].adjacent = new;
//	printf("Dans le node %d on va ajouter le noeud %d comme adjacent\n", )
}

void	add_edge_weight(int to_add, int vertex_target, t_vertex *vertices)
{
	int *new;

	if (!(new = malloc(sizeof(*new) * (vertices[vertex_target].nb_adjacent + 1))))
		return ;
	if (vertices[vertex_target].weight)
		ft_arraycpy(new, vertices[vertex_target].weight, vertices[vertex_target].nb_adjacent);
	new[vertices[vertex_target].nb_adjacent] = to_add;
	vertices[vertex_target].nb_adjacent += 1;
	
	free(vertices[vertex_target].weight);
	vertices[vertex_target].weight = new;
}

void	file_to_graph(int fd, t_vertex *vertices)
{
	char		*line;
	char		**line_divide;
	int			i;
	int			*temp;
	int			node1;
	int			node2;

	while ((get_next_line(fd, &line)) > 0)
	{
		if (!line || !line[0])
			return (free(line));
		line_divide = ft_split(line, '\t');
		node1 = atoi(line_divide[0]);
		i = 1;
		while (line_divide[i + 1])
		{
			add_vertex(atoi(line_divide[i]), node1, vertices);
			add_edge_weight(atoi(ft_strchr(line_divide[i], ',') + 1), node1, vertices);
			i++;
		}
		ft_free_split(line_divide);
		free(line);
	}
	free(line);
}

int		find_smallest_not_visited(t_vertex *vertices, char *visited)
{
	int index_of_min;
	int value_of_min;
	int i;

	i = 1;
	index_of_min = 0;
	value_of_min = 2147483647;
	while (visited[i])
	{
		if (visited[i] == '0' && vertices[i].distance_to_origin < value_of_min)
		{
			value_of_min = vertices[i].distance_to_origin;
			index_of_min = i;
		}
		i++;
	}
	return (index_of_min);
}

void	update_distance_to_origin(t_vertex *vertices, char *visited, int current_node)
{
	int i;
	int node_to_update;
	int distance_to_current_node;
	int	potential_new_distance;

	i = 0;
	while (i < vertices[current_node].nb_adjacent)
	{
		node_to_update = vertices[current_node].adjacent[i];
		distance_to_current_node = vertices[current_node].weight[i];
		potential_new_distance = vertices[current_node].distance_to_origin + distance_to_current_node;
		if (visited[node_to_update] == '0' && potential_new_distance < vertices[node_to_update].distance_to_origin)
		{
			vertices[node_to_update].distance_to_origin = potential_new_distance;
			printf("we update node %d\n", node_to_update);
		}
		i++;
	}
}


int		dijkstra(t_vertex *vertices, char *visited)
{
	int smallest_not_visited_index;

	while (one_node_not_visited(visited))
	{
		smallest_not_visited_index = find_smallest_not_visited(vertices, visited);
		printf("current smallest node not visited = %d\n", smallest_not_visited_index);
		visited[smallest_not_visited_index] = '1';
		update_distance_to_origin(vertices, visited, smallest_not_visited_index);
	}
	return (0);
}

int	main(int ac, char **av)
{
	char *visited;
	t_vertex *vertices;
	int fd;
	int nb_vertices = 200;
	int i;

	if (ac == 1)
		return (1);
	malloc_all(&vertices, &visited, nb_vertices + 1);
	ft_putstr("Malloc\n");
	fd = open(av[1], O_RDONLY);
	if (fd != -1)
		file_to_graph(fd, vertices);
	else
		return (fd);
	ft_putstr("Graph setting up done\n");
	dijkstra(vertices, visited);
	i = 1;
	while (i < nb_vertices + 1)
	{
		//printf("node %d: \n\b", i);
		print_array(vertices[i].adjacent, vertices[i].nb_adjacent);
		if (i == 7 || i == 37 || i == 59 || i ==82 || i == 99 || i == 115 || i == 133 || i == 165 || i ==188 || i == 197)
			printf("%d,", vertices[i].distance_to_origin);
		i++;
	}
	return (0);
}