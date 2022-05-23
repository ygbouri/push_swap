/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:34:30 by ygbouri           #+#    #+#             */
/*   Updated: 2022/05/20 16:54:28 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	comparer(char *str, char *s)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == s[i])
			i++;
		else
			return (0);
	}
	return (1);
}

void	appliquertwo(char *str, t_list **stack_a, t_list **stack_b)
{
	if (comparer(str, "rrr") == 1)
		rrr(stack_a, stack_b, 0);
	else if (comparer(str, "pa") == 1)
		pa(stack_a, stack_b, 0);
	else if (comparer(str, "pb") == 1)
		pb(stack_a, stack_b, 0);
	else
		error();
}

void	appliquer(char *str, t_list **stack_a, t_list **stack_b)
{
	if (comparer(str, "\n") == 1)
		error();
	if (comparer(str, "sa") == 1)
		sa(stack_a, 0);
	else if (comparer(str, "sb") == 1)
		sb(stack_b, 0);
	else if (comparer(str, "ss") == 1)
		ss(stack_a, stack_b, 0);
	else if (comparer(str, "ra") == 1)
		ra(stack_a, 0);
	else if (comparer(str, "rb") == 1)
		rb(stack_b, 0);
	else if (comparer(str, "rr") == 1)
		rr(stack_a, stack_b, 0);
	else if (comparer(str, "rra") == 1)
		rra(stack_a, 0);
	else if (comparer(str, "rrb") == 1)
		rrb(stack_b, 0);
	else
		appliquertwo(str, stack_a, stack_b);
}

void	checksortprint(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	indexdata(stack_a);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		appliquer(line, stack_a, stack_b);
		free(line);
	}
	indexdata(stack_a);
	if (sortnumber(stack_a) == 1)
	{
		if (!(*stack_b))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	else
		ft_printf("KO\n");
}

int	main(int ar, char **arg)
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;

	if (ar <= 1)
		exit(0);
	else
	{
		i = spli(arg);
		convert(arg, &stack_a);
		if (checkduplicatenumbre(&stack_a) == 1)
			error();
		checksortprint(&stack_a, &stack_b);
	}
	return (0);
}
