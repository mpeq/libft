/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpequeno <mpequeno@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:51:00 by mpequeno          #+#    #+#             */
/*   Updated: 2021/10/15 13:18:58 by mpequeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;

	if (!s1 || !set)
		return (0);
	first = 0;
	last = ft_strlen(s1) - 1;
	while (s1[first] && ft_strchr(set, s1[first]))
		first++;
	if (first == last + 1)
		return (ft_strdup(""));
	while (s1[last] && ft_strrchr(set, s1[last]))
		last--;
	return (ft_substr(s1, first, last - first + 1));
}
