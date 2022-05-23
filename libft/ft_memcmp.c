/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:29:12 by ygbouri           #+#    #+#             */
/*   Updated: 2021/11/07 15:55:50 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*ps1;
	const unsigned char		*ps2;
	int						i;

	ps1 = s1;
	ps2 = s2;
	i = 0;
	while (n > 0)
	{
		if (*(ps1 + i) == *(ps2 + i))
		{
			i++;
		}
		else if (*(ps1 + i) > *(ps2 + i))
		{
			return (*(ps1 + i) - *(ps2 + i));
		}
		else if (*(ps1 + i) < *(ps2 + i))
		{
			return (*(ps1 + i) - *(ps2 + i));
		}
		n--;
	}
	return (0);
}
