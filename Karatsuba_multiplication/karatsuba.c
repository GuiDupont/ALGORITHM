#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


void print_array(int *array, int len);


typedef struct	s_array
{
	int *array;
	int	len;
}				t_array;

void	ft_arraycpy(int *dst, int *src, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

int		ft_atoi_n(const char *str ,unsigned int i)
{
	unsigned int	n;
	int				negative;
	long			result;

	negative = 1;
	n = 0;
	result = 0;
	while (str[n] == ' ' || str[n] == '\n' || str[n] == '\t' || str[n] == '\v'
	|| str[n] == '\f' || str[n] == '\r')
		n++;
	if (str[n] == '-' || str[n] == '+')
	{
		if (str[n] == '-')
			negative = -negative;
		n++;
	}
	while (str[n] >= '0' && str[n] <= '9' && i != n)
		result = result * 10 + (str[n++] - '0');
	if (result < 0 && negative > 0)
		return (-1);
	else if (result < 0 && negative < 0 && result * negative != -2147483648)
		return (0);
	return (result * negative);
}

long long karatsuba_int(char *x, int lenx, char *y, int leny)
{
	long long int ac, bd, adbc, max;

	if (lenx == 1 || leny == 1)
		return (ft_atoi_n(y, leny) * ft_atoi_n(x, lenx));
	if (lenx >= leny)
		max = lenx;
	else
		max = leny;
	ac = karatsuba_int(x, lenx / 2, y, leny / 2);
	bd = karatsuba_int(&x[lenx / 2], lenx - lenx / 2, &y[leny / 2], leny - leny / 2);
	adbc = karatsuba_int(x, lenx / 2, &y[leny / 2], leny - leny / 2)
	 + karatsuba_int(&x[lenx / 2], lenx - lenx / 2, y, leny / 2);
	return (adbc * powl(10, max / 2) + ac * pow(10, max) + bd);
}

void	make_same_length(t_array *x, t_array *y)
{	
	int len_goal;
	int *array;
	int i = 0;
	

	len_goal = (x->len >= y->len) ? x->len : y->len; 
	if (len_goal != x->len)
	{
		if (!(array = malloc(sizeof(*array) * len_goal)))
			return ;
		ft_arraycpy(&array[len_goal - x->len], x->array, x->len);
		while(i < len_goal - x->len)
			array[i++] = 0;
		x->array = array;
		x->len = y->len;
	}
	if (len_goal != y->len)
	{
		if (!(array = malloc(sizeof(*array) * len_goal)))
			return ;
		ft_arraycpy(&array[len_goal - y->len], y->array, y->len);
		while(i < len_goal - y->len)
			array[i++] = 0;
		y->array = array;
		y->len = x->len;
	}
}
t_array	*make_same_length_2(t_array *x, int len_goal)
{	
	int *array;
	t_array *result;
	int i = 0;
	
	if (!(result = malloc(sizeof(*result))))
		return (NULL);
	if (!(array = malloc(sizeof(*array) * len_goal)))
		return (NULL);
	ft_arraycpy(&array[len_goal - x->len], x->array, x->len);
	while (i < len_goal - x->len)
		array[i++] = 0;
	result->array = array;
	result->len = len_goal;

	// print_array(x->array, x->len);
	// printf("lengoal: %d\n", len_goal);
	// print_array(result->array, result->len);
	return (result);
}

t_array *addition_t_array(t_array *x1, t_array *y1)
{
	t_array	*result, *x, *y;
	int		i;
	int		ret = 0;
	int		*temp;

	if (y1->len > x1->len)
	{
		x = make_same_length_2(x1, y1->len);	
	}
	else
		x = x1;
	if (x1->len > y1->len)
		y = make_same_length_2(y1, x1->len);
	else
		y = y1;
	i = y->len - 1;
	if (!(result = malloc(sizeof(*result))))
		return (NULL);
	if (!(result->array = malloc(sizeof(*(result->array)) * (x->len))))
		return (NULL);
	result->len = x->len;
	while (i != -1)
	{
		result->array[i] = x->array[i] + y->array[i] + ret;
		ret = 0;
		if (result->array[i] >= 10)
		{
			result->array[i] %= 10;
			ret = 1;
		}
		i--;
	}
	if (ret == 1)
	{
		result->len += 1;
		temp = malloc(sizeof(int) * result->len);
		ft_arraycpy(&temp[1], result->array, result->len - 1);
		temp[0] = 1; 
		result->array = temp;
	}
	return (result);
}

t_array *multiplication_t_array_size_1(t_array *x, t_array *y)
{
	t_array *result;
	int mult;

	if (x->len != 1 || y->len != 1)
		return (NULL);
	if (!(result = malloc(sizeof(*result))))
		return (NULL);
	mult = x->array[0] * y->array[0];
	if (mult >= 10)
		result->len = 2;
	else
		result->len = 1;
	if (!(result->array = malloc(sizeof(int) * result->len)))
		return (NULL);
	if (result->len == 2)
	{
		result->array[0] = mult / 10;
		result->array[1] = mult % 10;
	}
	else
		result->array[0] = mult;
	return (result);
}

t_array *init_t_array(int *array, int len)
{
	t_array *result;

	if (!(result = malloc(sizeof(*result))))
		return (NULL);
	if (!(result->array = malloc(sizeof(int) * len)))
		return (NULL);
	ft_arraycpy(result->array, array, len);
	result->len = len;
	return (result);
}

t_array *ten_pow_int_in_t_array(unsigned int y)
{
	t_array *result;
	int i = 1;

	if (!(result = malloc(sizeof(*result))))
		return (NULL);
	result->len = y + 1;
	if (!(result->array = malloc(sizeof(int) * result->len)))
		return (NULL);
	while (i < y)
		result->array[i++] = 0;
	result->array[0] = 1;
	return (result);
}

t_array *increase_array_pow_ten(t_array *x, int pow)
{
	t_array *result;
	int i;

	if (!(result =  malloc(sizeof(*result))))
		return (NULL);
	result->len = x->len + pow;
	if (!(result->array = malloc(sizeof(int) * (x->len + pow + 1))))
		return (NULL);
	ft_arraycpy(result->array, x->array, x->len);
	i = 0;
	while (i < pow)
	{
		result->array[x->len + i] = 0;
		i++;
	}
	return result;
}


t_array *karatsuba_array(t_array *x, t_array *y)
{
 	t_array *a, *b, *c, *d, *ac, *bd, *adbc, *temp, *temp2, *temp3, *test, *test2;
	int max;


	if (x->len == 1 || y->len == 1)
		return (multiplication_t_array_size_1(x, y));
	a = init_t_array(x->array, x->len / 2);
	b = init_t_array(&(x->array[x->len / 2]), x->len - x->len / 2);
	c = init_t_array(y->array, y->len / 2);
	d = init_t_array(&(y->array[y->len / 2]), y->len - y->len / 2);
	ac = karatsuba_array(a, c);
	bd = karatsuba_array(b, d);
	adbc = addition_t_array(karatsuba_array(a, d), karatsuba_array(b, c));
	if (x->len > y->len)
		max = x->len;
	else
		max = y->len;
	temp = increase_array_pow_ten(adbc, max / 2);
	temp2 = increase_array_pow_ten(ac, max);
	temp3 = addition_t_array(temp, temp2);
	return (addition_t_array(temp3, bd));
}

int *transform_str_to_array(char *str)
{
	int *result;
	int i = 0;
	int len;

	if (!str)
		return (NULL);
	len = strlen(str);
	if (!(result = malloc(sizeof(*result) * len)))
		return (NULL);
	while (str[i])
	{
		result[i] = str[i] - '0';
		i++;
	}
	return (result);
}

int main(int ac, char **av)
{
	t_array nbr1;
	t_array nbr2;
	t_array *add;
	t_array *pow;
	t_array *result;

	if (ac != 3)
		return (0);
	nbr1.array = transform_str_to_array(av[1]);
	nbr1.len = strlen(av[1]);
	nbr2.array = transform_str_to_array(av[2]);
	nbr2.len = strlen(av[2]);
	result = karatsuba_array(&nbr1, &nbr2);
	print_array(result->array, result->len);
	return (0);
}