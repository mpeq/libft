/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpequeno <mpequeno@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:28:57 by mpequeno          #+#    #+#             */
/*   Updated: 2021/10/15 13:16:57 by mpequeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numberstrings(char const *s, char c)
{
	int		i;
	int		nstr;

	i = 0;
	nstr = 0;
	if (!s[i])
		return (nstr);
	i = 1;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			nstr++;
		i++;
	}
	if (s[i - 1] != c)
		nstr++;
	return (nstr);
}

static char	*ft_copy(char const *s, char c, int *aux)
{
	int		j;
	int		len;
	char	*str;

	len = 0;
	while (s[(*aux) + len] && s[(*aux) + len] != c)
		len++;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	while (j < len)
	{
		str[j] = s[(*aux)];
		j++;
		(*aux)++;
	}
	str[j] = '\0';
	return (str);
}

static char	**ft_freesplit(char **split, int j)
{
	int	i;

	i = 0;
	while (i < j)
		free(split[i]);
	i++;
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		numberstr;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	numberstr = ft_numberstrings(s, c);
	split = malloc((numberstr + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (j < numberstr && s[i])
	{
		if (s[i] != c)
		{
			split[j++] = ft_copy(s, c, &i);
			if (!split[j - 1])
				return (ft_freesplit(split, j - 1));
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}
