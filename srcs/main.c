#include "../includes/algo.h"
#include <libexplain/open.h>


void	sorting_algo_war(void (*algo_1)(int*, int, int), void (*algo_2)(int*, int))
{
	int *array;
	clock_t begin;
	clock_t end;
	int	nb_elem;
	pid_t pid_fork;
	int status;
	double time_spent;
	int fd_algo_1;
	int fd_algo_2;
	int back_up;

	nb_elem = 20;
	fd_algo_1 = open("scores/algo1.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
	fd_algo_2 = open("scores/algo2.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
	status = 0;
	while (nb_elem <= 200)
	{
		srand(time (NULL));
		if (!(array = malloc(sizeof(*array) * nb_elem)))
			return ;
		back_up = dup(1);
		randomize_array(array, nb_elem, nb_elem);
		if ((pid_fork = fork()) == -1)
			exit(1);
		else if (pid_fork == 0)
		{
			begin = clock();
			algo_1(array, 0, nb_elem);
			end = clock();
			time_spent = (double)(end - begin) / (double)CLOCKS_PER_SEC;
			close(1);
			dup2(fd_algo_1, 1);
			printf("Quicksort spent %lf seconds to sorte an array of %d elements\n", time_spent, nb_elem);
			dup2(back_up, 1);
			exit(1);
		}
		else
		{
			begin = clock();
			algo_2(array, nb_elem);
			end = clock();
			time_spent = (double)(end - begin) / (double)CLOCKS_PER_SEC;
			waitpid(pid_fork, &status, 0);
			close(1);
			dup2(fd_algo_2, 1);
			printf("Insertion sort spent %lf seconds to sorte an array of %d elements\n", time_spent, nb_elem);
			
		}
		dup2(back_up, 1);
		close(back_up);
		free(array);
		nb_elem *= 5;
	}
}



int main (int ac, char **av)
{
	(void)ac;
	(void)av;
	sorting_algo_war(&ft_quicksort, &insertion_sort);
	return (0);
}
