/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 07:53:56 by ygbouri           #+#    #+#             */
/*   Updated: 2021/11/30 07:54:06 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		k = i;
		while (haystack[k] == needle[j] && k < len && needle[j])
		{
			k++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		else
			j = 0;
		i++;
	}
	return (NULL);
}
