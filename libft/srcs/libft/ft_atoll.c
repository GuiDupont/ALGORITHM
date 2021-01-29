/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:14:13 by gdupont           #+#    #+#             */
/*   Updated: 2021/01/28 12:38:22 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoll(const char *str)
{
	int			n;
	int			negative;
	long long	result;

	negative = 1;
	n = 0;
	result = 0;
	while (str[n] == ' ' || str[n] == '\n' || str[n] == '\t' || str[n] == '\v'
	|| str[n] == '\f' || str[n] == '\r')
		n++;
	if (str[n] == '-' || str[n] == '+')
	{
		if (str[n] == '-')
			negative = -1;
		n++;
	}
	while (str[n] >= '0' && str[n] <= '9')
		result = result * 10 + (str[n++] - '0');
	if (result < 0 && negative == 1)
		return (-1);
	return (result * negative);
}
