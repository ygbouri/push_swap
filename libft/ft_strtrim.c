/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 00:04:22 by ygbouri           #+#    #+#             */
/*   Updated: 2021/11/24 05:07:04 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

static int	verif(char const *set, char c)
{
	int	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (set[j] == c)
			return (1);
		j++;
	}
	return (0);
}

static int	boucle(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (verif(set, s1[i]) == 1)
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			i;
	int			j;
	char		*p;
	int			k;

	if (!s1 || !set)
		return ("");
	i = boucle(s1, set);
	k = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] != '\0' && verif(set, s1[j]) == 1)
		j--;
	p = (char *)malloc((j - i) + 2);
	if (!p)
		return (NULL);
	if (s1[i] && (i != 0 || j != (int)ft_strlen(s1)))
	{
		while (i <= j)
			p[k++] = s1[i++];
		p[k] = '\0';
		return (p);
	}
	p[0] = 0;
	return (p);
}
