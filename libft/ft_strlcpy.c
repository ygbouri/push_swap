/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:58:50 by ygbouri           #+#    #+#             */
/*   Updated: 2021/11/24 19:58:57 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	r;
	size_t	size;
	size_t	i;

	i = 0;
	r = ft_strlen(src);
	size = r;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && size > 0)
		{
			dst[i] = src[i];
			i++;
			size--;
		}
		dst[i] = '\0';
	}
	return (r);
}
