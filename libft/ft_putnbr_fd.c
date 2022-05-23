/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:51:35 by ygbouri           #+#    #+#             */
/*   Updated: 2021/11/23 00:15:55 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	char	c;
	long	n;

	n = nbr;
	if (n < 0)
	{
		c = '-';
		write (fd, &c, 1);
		n = n * (-1);
	}
	if (n > 9)
	{
		ft_putnbr_fd (n / 10, fd);
		ft_putnbr_fd (n % 10, fd);
	}
	if (n < 10)
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}
