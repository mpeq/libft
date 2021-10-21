/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpequeno <mpequeno@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:32:17 by mpequeno          #+#    #+#             */
/*   Updated: 2021/10/20 10:59:01 by mpequeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = malloc(size * count);
	if (!str)
		return (NULL);
	while (i < (size * count))
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
