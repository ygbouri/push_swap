/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:55:23 by ygbouri           #+#    #+#             */
/*   Updated: 2022/05/20 12:47:40 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*p;

	p = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst != NULL)
	{
		ft_lstadd_back(&p, ft_lstnew(f(lst->content), 0));
		if (!p)
		{
			ft_lstclear(&p, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (p);
}
