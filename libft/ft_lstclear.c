/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 03:59:34 by ygbouri           #+#    #+#             */
/*   Updated: 2022/05/13 09:00:04 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*p;

	p = NULL;
	if (*lst && del)
	{
		p = (*lst);
		while (p)
		{
			p = (*lst)->next;
			ft_lstdelone((*lst), del);
			(*lst) = p;
		}
		free(*lst);
	}
}
