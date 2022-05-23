/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:26:16 by ygbouri           #+#    #+#             */
/*   Updated: 2022/05/20 13:41:25 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a, int affich)
{
	int		temp;
	t_list	*nd;
	int		j;

	if (ft_lstsize((*stack_a)) > 1)
	{
		temp = (*stack_a)->content;
		j = (*stack_a)->i;
		nd = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		ft_lstadd_back(stack_a, ft_lstnew(temp, j));
		if (affich == 1)
			ft_printf("ra\n");
		free(nd);
	}
}

void	rb(t_list **stack_b, int affich)
{
	int		temp;
	t_list	*nd;
	int		j;

	if (ft_lstsize((*stack_b)) > 1)
	{
		temp = (*stack_b)->content;
		j = (*stack_b)->i;
		nd = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		ft_lstadd_back(stack_b, ft_lstnew(temp, j));
		if (affich == 1)
			ft_printf("rb\n");
		free(nd);
	}
}

void	rr(t_list **stack_a, t_list **stack_b, int affich)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (affich == 1)
		ft_printf("rr\n");
}

void	ft_lastmoins(t_list **stack_a)
{
	t_list	*nd;
	t_list	*p;

	if (stack_a)
	{
		p = *stack_a;
		while (p->next->next != NULL)
			p = p->next;
		nd = p->next;
		p->next = NULL;
		free(nd);
	}
}

void	rra(t_list **stack_a, int affich)
{
	int		temp;
	t_list	*p;

	if (ft_lstsize((*stack_a)) > 1)
	{
		p = (*stack_a);
		temp = ft_lstlast(p)->content;
		ft_lstadd_front(stack_a, ft_lstnew(temp, ft_lstlast(p)->i));
		ft_lastmoins(&p);
		if (affich == 1)
			ft_printf("rra\n");
	}
}
