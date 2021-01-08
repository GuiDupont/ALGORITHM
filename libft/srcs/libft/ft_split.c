/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 22:13:47 by gdupont           #+#    #+#             */
/*   Updated: 2020/12/07 12:16:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/libft.h"

static int	size(char const *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static int	size_dest(char const *str, char c)
{
	int	i;
	int	y;

	i = 0;
	y = 1;
	while (str[i])
	{
		if (str[i] != c)
		{
			if (size(&str[i], c))
				i = i + size(&str[i], c);
			else
				i++;
			y++;
		}
		else
			i++;
	}
	return (y);
}

char		**ft_split(char const *str, char c)
{
	char	**final;
	int		i;
	int		y;

	if (!str)
		return (NULL);
	if (!(final = malloc(sizeof(*final) * size_dest(str, c))))
		return (NULL);
	i = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			final[y] = ft_substr(&str[i], 0, size(&str[i], c));
			i = i + size(&str[i], c);
			y++;
		}
		if (str[i])
			i++;
	}
	final[y] = NULL;
	return (final);
}
