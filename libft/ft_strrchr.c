/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:55:19 by ygbouri           #+#    #+#             */
/*   Updated: 2021/11/20 01:56:26 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strrchr(const char *str, int arg)
{
	int				i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)str;
	i = ft_strlen(str);
	while (i > 0 && p[i] != (unsigned char)arg)
		i--;
	if (p[i] == (unsigned char)arg)
		return ((char *)p + i);
	return (NULL);
}
