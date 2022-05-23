/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:28:22 by ygbouri           #+#    #+#             */
/*   Updated: 2022/05/20 13:28:53 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_list **stack_b, int affich)
{
	int		temp;
	t_list	*p;

	if (ft_lstsize((*stack_b)) > 1)
	{
		p = (*stack_b);
		temp = ft_lstlast(p)->content;
		ft_lstadd_front(stack_b, ft_lstnew(temp, ft_lstlast(p)->i));
		ft_lastmoins(&p);
		if (affich == 1)
			ft_printf("rrb\n");
	}
}

void	rrr(t_list **stack_a, t_list **stack_b, int affich)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (affich == 1)
		ft_printf("rrr\n");
}

void	ft_lastmoinspp(t_list **stack_a, t_list **stack_b)
{
	t_list	*p;

	if (stack_a)
	{
		p = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_lstadd_front(stack_b, ft_lstnew(p->content, p->i));
		free(p);
	}
}

void	pb(t_list **stack_a, t_list **stack_b, int affich)
{
	if (ft_lstsize(*stack_a) >= 1)
	{
		ft_lastmoinspp(stack_a, stack_b);
		if (affich == 1)
			ft_printf("pb\n");
	}
}

void	pa(t_list **stack_a, t_list **stack_b, int affich)
{
	if (ft_lstsize(*stack_b) >= 1)
	{
		ft_lastmoinspp(stack_b, stack_a);
		if (affich == 1)
			ft_printf("pa\n");
	}
}
