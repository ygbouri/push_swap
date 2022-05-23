/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:27:05 by ygbouri           #+#    #+#             */
/*   Updated: 2021/11/30 22:42:55 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*psrc;
	char		*pdst;
	size_t		i;
	size_t		j;

	i = 0;
	psrc = (char *)src;
	pdst = (char *)dst;
	if (!pdst && !psrc)
		return (NULL);
	j = len;
	if (dst > src)
	{
		while (len)
		{
			len--;
			pdst[len] = psrc[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
