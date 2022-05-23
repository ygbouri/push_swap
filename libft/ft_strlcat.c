/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:00:15 by ygbouri           #+#    #+#             */
/*   Updated: 2021/11/24 20:00:26 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	r;
	size_t	i;
	size_t	j;
	size_t	res;

	r = ft_strlen(dst);
	i = 0;
	j = r;
	if (dstsize > r)
		res = ft_strlen(src) + r;
	else
		res = ft_strlen(src) + dstsize;
	if (dstsize != 0 && r < dstsize -1)
	{
		while (src[i] && r < dstsize - 1)
		{
			dst[r] = src[i];
			r++;
			i++;
		}
		dst[r] = '\0';
	}
	return (res);
}
