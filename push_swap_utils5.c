/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:29:47 by ygbouri           #+#    #+#             */
/*   Updated: 2022/05/20 13:40:55 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

void	sorttree(t_list **stack_a)
{
	t_list	*p;

	p = (*stack_a);
	if (p->i == 1 && p->next->i == 0)
		sa(stack_a, 1);
	else if (p->i == 1 && p->next->i == 2)
		rra(stack_a, 1);
	else if (p->i == 2 && p->next->i == 1)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (p->i == 2 && p->next->i == 0)
		ra(stack_a, 1);
	else if (p->i == 0 && p->next->i == 2)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
}

int	getposition(t_list *stack_a, int i)
{
	t_list	*p;
	int		j;

	p = stack_a;
	j = 1;
	while (ft_lstsize(stack_a) > 0)
	{
		if (p->i == i)
			return (j);
		p = p->next;
		j++;
	}
	return (j);
}

int	getmiddle(t_list *stack_a)
{
	t_list	*temp;
	t_list	*tempp;
	int		j;

	if (ft_lstsize(stack_a) % 2 == 0)
		return (ft_lstsize(stack_a) / 2);
	temp = stack_a;
	tempp = stack_a;
	j = 0;
	while (temp->next)
	{
		temp = temp->next->next;
		tempp = tempp->next;
	}
	return (tempp->i);
}

void	pbandpa(t_list **stack_a, t_list **stack_b, int i)
{
	pb(stack_a, stack_b, 1);
	indexdata(stack_a);
	if (i == 0)
		sorttree(stack_a);
	else
		sortfour(stack_a, stack_b);
	pa(stack_a, stack_b, 1);
	indexdata(stack_a);
}
