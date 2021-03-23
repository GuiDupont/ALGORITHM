#include "../includes/scheduling.h"
/*
**	Your task in this problem is to run the greedy algorithm that schedules jobs in decreasing order of the difference (weight - length).  
	Recall from lecture that this algorithm is not always optimal.  
	IMPORTANT: if two jobs have equal difference (weight - length), you should schedule the job with higher weight first.  
	Beware: if you break ties in a different way, you are likely to get the wrong answer.  You should report the sum of weighted completion times of the resulting schedule --- a positive integer --- in the box below. 
**
**
**
*/

int main(int ac, char **av)
{
	FILE *fd;
	int nb_jobs;
	t_jobs **jobs;
	int i = 0;
	//int y;
	int weight_sum = 0;
	int completion_time = 0;

	if (ac != 2)
		return (1);
	fd = fopen(av[1], "r");
	if (fd < 0)
		return (1);
	fscanf(fd, "%d\n", &nb_jobs);
	if (!(jobs = malloc(sizeof(*jobs) * (nb_jobs + 1))))
		return (1);
	while (i < nb_jobs)
	{
		jobs[i] = malloc(sizeof(**jobs));
		if (!jobs[i])
			return (1);
		fscanf(fd, "%d %d\n", &(jobs[i]->w), &(jobs[i]->l));
		jobs[i]->ratio = jobs[i]->w / jobs[i]->l;
		i++;
	}
	jobs[i] = NULL;
	ft_quicksort_j(jobs, nb_jobs);
	i = 0;
	while (i < nb_jobs) // here we sort in decreasing order jobs with same diff following their weight
	{
		// y = i;
		// while (jobs[y] && jobs[y + 1] && jobs[i]->diff == jobs[y + 1]->diff)
		// 	y++;
		// if (y != i)
		// {	
		// 	ft_insertionsort_j_w_d(&jobs[i], y - i + 1);
		// 	i = y;
		// }
		printf("%f ", jobs[i]->ratio);
		i++;

	}
	i = 0;
	while (i < nb_jobs)
	{
		completion_time += jobs[i]->l;
		weight_sum += completion_time * jobs[i]->w; 
		i++;
	}
	printf("answer %d\n", completion_time);
}

//  80 80 40 85 43 87 87 86 44 89 91 90 90 93 93 46 47 96 96 96 99 98 98 99 49 98 50 51 
//  51 51 51 55 57 58 58 58 59 62 62 62 63 64 65 65 65 66 67 67 68 69 71 72 72 
//  73 74 74 76 76 77 77 79 79 81 81 82 84 84 84 86 86 87 88 92 93 93 95 95 98 99