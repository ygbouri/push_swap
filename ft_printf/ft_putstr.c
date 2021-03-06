/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:51:45 by ygbouri           #+#    #+#             */
/*   Updated: 2022/04/13 22:44:55 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putstr(char *s)
{
	if (s)
	{
		write (1, s, ft_strleng(s));
	}
	else
	{
		write (1, "(null)", 6);
		return (6);
	}
	return (ft_strleng(s));
}
