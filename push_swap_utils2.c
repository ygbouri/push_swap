/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:10:58 by ygbouri           #+#    #+#             */
/*   Updated: 2022/05/20 15:41:37 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getmax(t_list *stack_a)
{
	int		max;
	t_list	*p;

	p = stack_a;
	max = p->i;
	while (p->next)
	{
		if (p->i > max)
			max = p->i;
		p = p->next;
	}
	if (p->i > max)
		max = p->i;
	return (max);
}

void	sa(t_list **stack_a, int affich)
{
	int	temp;
	int	j;

	j = 0;
	if (ft_lstsize((*stack_a)) > 1)
	{
		temp = (*stack_a)->content;
		j = (*stack_a)->i;
		(*stack_a)->content = (*stack_a)->next->content;
		(*stack_a)->i = (*stack_a)->next->i;
		(*stack_a)->next->content = temp;
		(*stack_a)->next->i = j;
		if (affich == 1)
			ft_printf("sa\n");
	}
}

void	sb(t_list **stack_b, int affich)
{
	int	temp;
	int	j;

	if (ft_lstsize((*stack_b)) > 1)
	{
		temp = (*stack_b)->content;
		j = (*stack_b)->i;
		(*stack_b)->content = (*stack_b)->next->content;
		(*stack_b)->i = (*stack_b)->next->i;
		(*stack_b)->next->content = temp;
		(*stack_b)->next->i = j;
		if (affich == 1)
			ft_printf("sb\n");
	}
}

void	ss(t_list **stack_a, t_list **stack_b, int affich)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (affich == 1)
		ft_printf("ss\n");
}

void	sorting(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a, 1);
	else if (ft_lstsize((*stack_a)) == 3)
		sorttree(stack_a);
	else if (ft_lstsize((*stack_a)) == 4)
		sortfour(stack_a, stack_b);
	else if (ft_lstsize((*stack_a)) == 5)
		sortfive(stack_a, stack_b);
	else
		sortbigsize(stack_a, stack_b);
}
