/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:45:46 by ygbouri           #+#    #+#             */
/*   Updated: 2022/05/20 13:13:28 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remplirbprime(t_list **stack_a, t_list **stack_b, int i, int j)
{
	t_list	*p;

	p = *stack_a;
	while (ft_lstsize(*stack_a) > 0)
	{
		if (p->i < i)
		{
			pb(stack_a, stack_b, 1);
			rb(stack_b, 1);
			i++;
		}
		else if (p->i < (i + j))
		{
			pb(stack_a, stack_b, 1);
			i++;
		}
		else
			ra(stack_a, 1);
		p = *stack_a;
		if (ft_lstsize(*stack_b) > 1)
			if ((*stack_b)->i < (*stack_b)->next->i)
				sb(stack_b, 1);
	}
}

void	remplirb(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		j;
	t_list	*p;

	i = 1;
	j = 15;
	if (ft_lstsize(*stack_a) > 250)
		j = 25;
	p = *stack_a;
	remplirbprime(stack_a, stack_b, i, j);
}

void	remplira(t_list **stack_a, t_list **stack_b)
{
	int		pos;
	int		middle;
	int		i;

	while (ft_lstsize(*stack_b) > 0)
	{
		if (*stack_b)
		{
			i = 0;
			pos = getposition(*stack_b, getmax(*stack_b));
			middle = getposition(*stack_b, getmiddle(*stack_b));
			if (pos <= middle)
			{
				while (i++ < pos - 1)
					rb(stack_b, 1);
				pa(stack_a, stack_b, 1);
			}
			else if (pos > middle)
			{
				while (i++ < ft_lstsize(*stack_b) - pos + 1)
					rrb(stack_b, 1);
				pa(stack_a, stack_b, 1);
			}
		}
	}
}

void	sortbigsize(t_list **stack_a, t_list **stack_b)
{
	remplirb(stack_a, stack_b);
	remplira(stack_a, stack_b);
}

int	main(int ar, char **arg)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ar <= 1)
		exit(0);
	else
	{
		if (spli(arg) == 0)
			error();
		else
		{
			convert(arg, &stack_a);
			if (checkduplicatenumbre(&stack_a) == 1)
				error();
			if (sortnumber(&stack_a) == 0)
			{
				indexdata(&stack_a);
				sorting(&stack_a, &stack_b);
			}
			else if (sortnumber(&stack_a) == 1)
				exit(0);
		}
	}
	return (0);
}
