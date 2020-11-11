#include "../includes/algo.h"

void	sorting_algo_war(void (*algo_1)(int*, int, int), void (*algo_2)(int*, int))
{
	int *array;
	clock_t begin;
	clock_t end;
	int	nb_elem;
	pid_t pid_fork;
	int status;
	double time_spent;

	nb_elem = 20;
	status = 0;
	while (nb_elem <= 200)
	{
		srand(time (NULL));
		if (!(array = malloc(sizeof(*array) * nb_elem)))
			return ;
		randomize_array(array, nb_elem, nb_elem);
		if ((pid_fork = fork()) == -1)
			exit(1);
		else if (pid_fork == 0)
		{
			begin = clock();
			algo_1(array, 0, nb_elem);
			end = clock();
			time_spent = (double)(end - begin) / (double)CLOCKS_PER_SEC;
			printf("Quicksort spent %lf seconds to sorte an array of %d elements\n", time_spent, nb_elem);
			exit(1);
		}
		else
		{
			begin = clock();
			algo_2(array, nb_elem);
			end = clock();
			time_spent = (double)(end - begin) / (double)CLOCKS_PER_SEC;
			waitpid(pid_fork, &status, 0);
			printf("Fusion sort spent %lf seconds to sorte an array of %d elements\n", time_spent, nb_elem);
		}
		nb_elem *= 10;
		free(array);
	}
}

int		choose_algo(void *algo_chosen[2], void *algo_table[NB_ALGOS])
{
	char	*line;
	char	**instructions;
	int		instruct[2];


	printf("Here is the list of algos\n1 : quick sort\n2 : insertion sort\n3 : fusion sort\nEnter the number of the 2 algo you want to make compete\nEnter \"0\" to quit\n");
	get_next_line(0, &line);
	if (line[0] == '0')
	{
		free(line);
		exit(0);
	}
	instructions = ft_split(line, ' ');
	if (ft_count_split(instructions) != 2)
	{
		ft_free_split(instructions);
		return (0);
	}
	instruct[0] = ft_atoi(instructions[0]);
	instruct[1] = ft_atoi(instructions[1]);
	if (instruct[0] > NB_ALGOS || instruct[0] < 0 || instruct[1] > NB_ALGOS || instruct[1] < 0)
	{
		ft_free_split(instructions);
		return (0);
	}
	algo_chosen[0] = algo_table[instruct[0]];
	algo_chosen[1] = algo_table[instruct[1]];
	return (1);
}

void	set_algo_table(void *algo_table[NB_ALGOS + 1])
{
	algo_table[0] = NULL;
	algo_table[1] = &ft_quicksort;
	algo_table[2] = &insertion_sort;
	algo_table[3] = &fusion_sort;
}

int main (int ac, char **av)
{
	(void)ac;
	(void)av;
	void *algo_chosen[2];
	void *algo_table[NB_ALGOS + 1];

	set_algo_table(algo_table);
	while (1)
	{
		if (choose_algo(algo_chosen, algo_table))
			sorting_algo_war(algo_chosen[0], algo_chosen[1]);
	}
	return (0);
}
