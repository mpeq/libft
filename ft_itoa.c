/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpequeno <mpequeno@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:03:45 by mpequeno          #+#    #+#             */
/*   Updated: 2021/10/15 13:37:55 by mpequeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(long long nb)
{
	size_t	i;

	i = 1;
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static char	*ft_values(long long nb, int sign)
{
	char	*str;
	size_t	size;

	size = ft_size(nb) + sign ;
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (sign)
		str[0] = '-';
	str[size] = '\0';
	size--;
	while (nb >= 10)
	{
		str[size] = nb % 10 + '0';
		size--;
		nb = nb / 10;
	}
	str[size] = nb + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	long long			nb;
	int					sign;

	nb = n;
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		nb = nb * -1;
	}
	return (ft_values(nb, sign));
}
