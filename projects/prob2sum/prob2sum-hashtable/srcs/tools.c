#include "../includes/prob2sum.h"

void	add_elem_to_table(t_list **table, long long nb)
{
	int		nb_mod;
	t_list	*current;
	t_list	*previous;

	nb_mod = nb % 10000000;
	if (nb_mod < 0)
		nb_mod *= -1;
	current = table[nb_mod];
	while (current)
	{
		if (current->content == (void *)nb)
			return ;
		previous = current;
		current = current->next;
	}
	current = malloc(sizeof(**table));
	current->content = (void *)nb;
	current->next = NULL;
	if (table[nb_mod] == NULL)
		table[nb_mod] = current;
	else
		previous->next = current;
}

t_list	**malloc_hashtable(int size)
{
	int 		i = 0;
	t_list		**already_seen = NULL;

	if (!(already_seen = malloc(sizeof(*already_seen) * (size + 1))))
		return (NULL);
	while (i < (size + 1))
	{
		already_seen[i] = NULL;
		i++;
	}
	return (already_seen);
}

void	ft_swap_ll(long long *a, long long *b)
{
	long long temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
