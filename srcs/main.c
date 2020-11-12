#include "../includes/algo.h"

void	sorting_algo_war(t_algo algo1, t_algo algo2)
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
	while (nb_elem <= 200000)
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
			algo1.function(array, nb_elem);
			end = clock();
			time_spent = (double)(end - begin) / (double)CLOCKS_PER_SEC;
			printf("%s spent %lf seconds to sorte an array of %d elements\n", algo1.name, time_spent, nb_elem);
			exit(1);
		}
		else
		{
			begin = clock();
			algo2.function(array, nb_elem);
			end = clock();
			time_spent = (double)(end - begin) / (double)CLOCKS_PER_SEC;
			waitpid(pid_fork, &status, 0);
			printf("%s spent %lf seconds to sorte an array of %d elements\n", algo2.name, time_spent, nb_elem);
		}
		nb_elem *= 10;
		free(array);
	}
}

int		choose_algo(t_algo algo_chosen[2], t_algo algo_structs[NB_ALGOS + 1])
{
	char	*line;
	char	**instructions;
	int		instruct[2];


	printf("Here is the list of algos\n#1 : quick sort\n#2 : insertion sort\n#3 : fusion sort\nEnter the id of the 2 algo you want to make compete\nEnter \"0\" to quit\n");
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
	if (instruct[0] > NB_ALGOS || instruct[0] < 1 || instruct[1] > NB_ALGOS || instruct[1] < 1)
	{
		ft_free_split(instructions);
		return (0);
	}
	algo_chosen[0] = algo_structs[instruct[0]];
	algo_chosen[1] = algo_structs[instruct[1]];
	return (1);
}

void	set_algo_table(t_algo algo_structs[NB_ALGOS + 1])
{
	algo_structs[1].function = &ft_quicksort;
	algo_structs[1].name = "Quick sort";
	algo_structs[2].function = &insertion_sort;
	algo_structs[2].name = "Insertion sort";
	algo_structs[3].function = &fusion_sort;
	algo_structs[3].name = "Fusion sort";
}

int main (int ac, char **av)
{
	(void)ac;
	(void)av;
	t_algo algo_chosen[2];
	t_algo algo_structs[NB_ALGOS + 1];

	set_algo_table(algo_structs);
	ft_putstr("salut\n");
	while (1)
	{
		if (choose_algo(algo_chosen, algo_structs))
			sorting_algo_war(algo_chosen[0], algo_chosen[1]);
	}
	return (0);
}
