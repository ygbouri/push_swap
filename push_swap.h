/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:49:49 by ygbouri           #+#    #+#             */
/*   Updated: 2022/05/20 15:45:30 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <limits.h>

void	free_tab(char **s);
void	error(void);
void	pbandpa(t_list **stack_a, t_list **stack_b, int i);
int		sortnumber(t_list **nd);
int		checkduplicatenumbre(t_list **nd);
void	convert(char **str, t_list **nd);
int		spli(char **str);
void	sa(t_list **stack_a, int affich);
void	sb(t_list **stack_b, int affich);
void	ss(t_list **stack_a, t_list **stack_b, int affich);
void	ra(t_list **stack_a, int affich);
void	rb(t_list **stack_b, int affich);
void	rr(t_list **stack_a, t_list **stack_b, int affich);
void	ft_lastmoins(t_list **stack_a);
void	rra(t_list **stack_a, int affich);
void	rrb(t_list **stack_b, int affich);
void	rrr(t_list **stack_a, t_list **stack_b, int affich);
void	ft_lastmoinspp(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b, int affich);
void	pa(t_list **stack_a, t_list **stack_b, int affich);
void	indexdata(t_list **stack_a);
int		getposition(t_list *stack_a, int i);
int		getmiddle(t_list *stack_a);
int		getmax(t_list *stack_a);
void	remplirbprime(t_list **stack_a, t_list **stack_b, int i, int j);
void	remplirb(t_list **stack_a, t_list **stack_b);
void	remplira(t_list **stack_a, t_list **stack_b);
void	sorttree(t_list **stack_a);
void	sortbigsize(t_list **stack_a, t_list **stack_b);
void	sortfour(t_list **stack_a, t_list **stack_b);
void	sortfive(t_list **stack_a, t_list **stack_b);
void	sorting(t_list **stack_a, t_list **stack_b);
#endif