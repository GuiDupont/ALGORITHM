#include "../includes/prob2sum.h"

/*
** The goal of this exercise is to determine how many times the sum of 2 integers 
** from a dataset is >= to -10000 and <= 10000. X and Y must be different
*/

int		count_mathching_int_in_lst(t_list *list, long long lower_bound, long long upper_bound, long long nb, char *visited)
{
	int i = 0;
	long long t;

	while (list)
	{
		if (list->content >= (void *)lower_bound &&
			list->content <= (void *)upper_bound)
			{
				t = nb + (long long)list->content + 10000;
				ft_putnbr((int)t);
				ft_putchar('\n');
				visited[t] = '1';
			}
		list = list->next;
	}
	return (i);
}

int		count_matching_int_in_table(t_list **table, long long nb, char *visited)
{
	long long	lower_bound;
	long long	upper_bound;
	long long	lower_bound_mod;
	long long	upper_bound_mod;
	int count = 0;

	lower_bound = nb * -1 - 10000;
	upper_bound = nb * -1 + 10000;
	if (lower_bound > upper_bound)
		ft_swap_ll(&lower_bound, &upper_bound);
	lower_bound_mod = lower_bound % 10000000;
	upper_bound_mod = upper_bound % 10000000;
	if (lower_bound_mod < 0)
		lower_bound_mod *= -1;
	if (upper_bound_mod < 0)
		upper_bound_mod *= -1;
	while (lower_bound_mod <= upper_bound_mod)
	{
		if (table[lower_bound_mod])
			count += count_mathching_int_in_lst(table[lower_bound_mod], lower_bound, upper_bound, nb, visited);
		lower_bound_mod++;
	}
	return (count);
}

char	*malloc_t_visited(int size)
{
	int i;
	char *visited;
	i = 0;

	visited = malloc(sizeof(*visited) * (size + 1));
	if (!visited)
		return (NULL);
	while (i < size)
		visited[i++] = '0';
	return (visited); 
}

int		count_nb_visited(char *visited, int size)
{
	int i = 0;
	int count = 0;

	while (i < size)
	{
		if (visited[i] == '1')
			count++;
		i++;
	}
	return (count);
}

int main(int ac, char **av)
{
	int				fd;
	char			*line;
	long long		nb;
	t_list			**already_seen;
	int				i = 0;
	int 			count = 0;
	char			*visited;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (fd);
	already_seen = malloc_hashtable(100000001);
	visited = malloc_t_visited(20001);
	while (get_next_line(fd, &line) > 0)
	{
		nb = ft_atoll(line);
		add_elem_to_table(already_seen, nb);
		count_matching_int_in_table(already_seen, nb, visited);
		free(line);
		i++;
	}
	count = count_nb_visited(visited, 20001);
	ft_printf("%d\n", count);
}
