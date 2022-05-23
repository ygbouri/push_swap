/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:27:41 by ygbouri           #+#    #+#             */
/*   Updated: 2021/11/30 11:43:01 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int arg)
{
	int	i;

	i = 0;
	while (*(str + i) != (unsigned char)arg && *(str + i) != '\0')
	{
		i++;
	}
	if (*(str + i) == (unsigned char)arg)
	{
		return ((char *)str + i);
	}
	return (NULL);
}
