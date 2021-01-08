#include "graph.h"

// void	ft_arraycpy(int *dst, int *src, int len)
// {
// 	int i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// }

// void	set_up_vertices(char *line, t_vertices *vertices)
// {
// 	char		**line_2d;
// 	int			i;
// 	int			*temp;
// 	int			node1;
// 	int			node2;

// 	line_2d = ft_split(line, ' ');
// 	node1 = atoi(line_2d[0]);
// 	node2 = atoi(line_2d[1]);
// 	if (node1 == node2)
// 		return ;
// 	vertices[node1].nb_adjacent += 1;
// 	if (!(temp = malloc(sizeof(*temp) * vertices[node1].nb_adjacent)))
// 		return ;
// 	ft_arraycpy(temp, vertices[node1].adjacent_v, vertices[node1].nb_adjacent - 1);
// 	temp[vertices[node1].nb_adjacent - 1] = node2;
// 	free(vertices[node1].adjacent_v);
// 	vertices[node1].adjacent_v = temp;
// 	ft_free_split(line_2d);
// }


// void	file_to_graph(int fd, t_graph *graph)
// {
// 	char		*line;
// 	int			i;
// ;
// 	while (get_next_line(fd, &line) > 0) //here we set up all our vertices
// 	{
// 		//puts("salut");
// 		set_up_vertices(line, graph->vertices);
// 		free(line);
// 	}
// 	free(line);
// }

int	main(int ac, char **av)
{
	int i = 0;
	int fd;
	

	//ft_putendl("salut");
	//while (i < 8757)
	//	visited[i++] = 'n';
	
	// fd = open("scc_short.txt", O_RDONLY);
	// if (fd < 0)
	// 	return (fd);
	// puts("salut");
	// file_to_graph(fd, &graph);
	// close(fd);
	// if (ft_nb_edges(graph.edges.next) < min)
	// {
	// 	min = ft_nb_edges(graph.edges.next);
	// 	printf("new min = %d\n", min);
	// }
	// free_graph(&graph);
	// if (i % 20 == 0)
	// 	printf("%d\n", i);
	// i++;

	return (0);
}