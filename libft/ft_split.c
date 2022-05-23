/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 04:07:33 by ygbouri           #+#    #+#             */
/*   Updated: 2022/05/18 15:32:41 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_compte_mot(char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] && (s[i] == c))
		i++;
	while (s[i] != '\0')
	{
		j = i;
		while (s[j] != c && s[j] != '\0')
		{
			if (s[j + 1] == c || s[j + 1] == '\0')
				k++;
			j++;
			i++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (k);
}

static char	**ft_libmem(char **p, int res)
{
	int	i;

	i = 0;
	while (i < res)
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}

static int	ft_iter(char const *s, int i, int j)
{
	if (s[j] == '\0')
	{
		i = j;
	}
	else
	{
		i = j + 1;
	}
	return (i);
}

static char	**ft_remplir(char **p, char const *s, char c)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (s[i] && (s[i] == c))
		i++;
	while (*(s + i) != '\0')
	{
		j = i;
		while (s[j] != c && s[j] != '\0')
			j++;
		if (s[i] != c)
		{
			p[res] = ft_substr(s, i, j - i);
			if (!p[res])
				return (ft_libmem(p, res));
			res++;
		}
		i = ft_iter(s, i, j);
	}
	p[res] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	p = (char **)malloc((ft_compte_mot(s, c) + 1) * sizeof(char *));
	if (!p)
	{
		free(p);
		return (NULL);
	}
	if (ft_remplir(p, s, c) == NULL)
		return (NULL);
	return (p);
}
