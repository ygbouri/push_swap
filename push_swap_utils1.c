/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:33:17 by ygbouri           #+#    #+#             */
/*   Updated: 2022/05/20 13:45:10 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortfour(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	k;
	int	j;

	if (stack_a)
	{
		i = 0;
		k = getposition(*stack_a, 0);
		j = ft_lstsize(*stack_a) / 2;
		if (k <= j)
		{
			k = getposition(*stack_a, 0) - 1;
			while (i++ < k)
				ra(stack_a, 1);
			pbandpa(stack_a, stack_b, 0);
		}
		else if (k > j)
		{
			i = 0;
			k = ft_lstsize(*stack_a) - getposition(*stack_a, 0) + 1;
			while (i++ < k)
				rra(stack_a, 1);
			pbandpa(stack_a, stack_b, 0);
		}
	}
}

void	sortfive(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	k;
	int	j;

	if (stack_a)
	{
		i = 0;
		k = getposition(*stack_a, 0);
		j = getposition(*stack_a, getmiddle(*stack_a));
		if (k <= j)
		{
			k = getposition(*stack_a, 0) - 1;
			while (i++ < k)
				ra(stack_a, 1);
			pbandpa(stack_a, stack_b, 1);
		}
		else if (k > j)
		{
			i = 0;
			k = ft_lstsize(*stack_a) - getposition(*stack_a, 0) + 1;
			while (i++ < k)
				rra(stack_a, 1);
			pbandpa(stack_a, stack_b, 1);
		}
	}	
}

void	trier(int *tab, t_list **stack_a)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < ft_lstsize(*stack_a))
	{
		j = i + 1;
		while (j < ft_lstsize(*stack_a))
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}	
}

void	pushindex(int *tab, t_list **stack_a)
{
	int		i;
	int		j;
	t_list	*p;

	j = 0;
	i = ft_lstsize(*stack_a);
	while (j < i)
	{
		p = *stack_a;
		while (p->next)
		{
			if (tab[j] == p->content)
				p->i = j;
			p = p->next;
		}
		if (tab[j] == p->content)
			p->i = j;
		j++;
	}
}

void	indexdata(t_list **stack_a)
{
	t_list	*p;
	int		*tab;
	int		i;

	i = 0;
	if (stack_a)
	{
		p = *stack_a;
		tab = (int *)malloc(ft_lstsize((*stack_a)) * sizeof(int));
		while (p->next)
		{
			tab[i++] = p->content;
			p = p->next;
		}
		tab[i] = p->content;
		trier(tab, stack_a);
		pushindex(tab, stack_a);
		free(tab);
	}
}
