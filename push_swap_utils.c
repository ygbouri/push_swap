/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 07:49:40 by ygbouri           #+#    #+#             */
/*   Updated: 2022/05/22 13:15:46 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sortnumber(t_list **nd)
{
	int		j;
	int		k;
	t_list	*tem;
	t_list	*p;

	j = 0;
	k = 0;
	p = *nd;
	while (p->next != NULL)
	{
		tem = p->next;
		while (tem->next != NULL)
		{
			if (p->content > tem->content)
				return (0);
			tem = tem->next;
		}
		if (p->content > tem->content)
			return (0);
		p = p->next;
	}
	return (1);
}

int	checkduplicatenumbre(t_list **nd)
{
	int		j;
	int		k;
	t_list	*p;
	t_list	*t;

	j = 0;
	k = 1;
	p = *nd;
	while (p->next != NULL)
	{
		t = p->next;
		while (t->next != NULL)
		{
			if (p->content == t->content)
				return (1);
			t = t->next;
		}
		if (p->content == t->content)
			return (1);
		p = p->next;
	}
	return (0);
}

void	convert(char **str, t_list **nd)
{
	int		j;
	char	**s;
	int		k;
	int		i;

	j = 0;
	i = 1;
	k = 0;
	while (str[i])
	{
		s = ft_split(str[i], ' ');
		j = 0;
		while (s[j])
		{
			k = ft_atoi(s[j]);
			ft_lstadd_back(nd, ft_lstnew(k, 0));
			j++;
		}
		i++;
		free_tab(s);
	}	
}

int	loop(char **s, int j)
{
	int	k;

	k = 0;
	while (s[j][k])
	{
		if (k == 0 && (s[j][k] == '+' || s[j][k] == '-'))
		{
			if (ft_isdigit(s[j][k + 1]) == 1)
				k++;
			else
				return (1);
		}
		else if (s[j][k] == '-' || s[j][k] == '+')
		{
			if ((ft_isdigit(s[j][k - 1]) == 0)
				&& (ft_isdigit(s[j][k + 1]) == 1))
				k++;
			else
				return (1);
		}
		else if (ft_isdigit(s[j][k]) == 0)
			return (1);
		k++;
	}
	return (0);
}

int	spli(char **str)
{
	char	**s;
	int		j;
	int		i;
	int		t;

	i = 1;j = 0;
	t = 0;
	if (str[1][0] == '\0')
		error();
	while (str[i])
	{
		s = ft_split(str[i], ' ');
		j = 0;
		while (s[j])
		{
			if (loop(s, j) == 1)
				return (0);
			if (j >= 1)
				t++;
			j++;
		}
		t++;
		i++;
		free_tab(s);
	}
	return (t);
}
