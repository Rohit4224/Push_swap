/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_pa_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:18:13 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/21 20:34:46 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_sa(t_node **a)
{
	t_node	*ptr;
	t_node	*ptr2;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	ptr = *a;
	ptr2 = ptr->next;
	*a = ptr2;
	ptr->next = ptr2->next;
	ptr2->next = ptr;
	return ;
}

void	checker_sb(t_node **b)
{
	t_node	*p;
	t_node	*p2;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	p = *b;
	p2 = p->next;
	*b = p2;
	p->next = p2->next;
	p2->next = p;
}

void	checker_ss(t_node **a, t_node **b)
{
	t_node	*a01;
	t_node	*a02;
	t_node	*b01;
	t_node	*b02;

	a01 = *a;
	b01 = *b;
	a02 = a01->next;
	b02 = b01->next;
	*a = a01->next;
	*b = b01->next;
	a01->next = a02->next;
	b01->next = b02->next;
	a02->next = a01;
	b02->next = b01;
	return ;
}

// b to a

void	checker_pa(t_node **b, t_node **a)
{
	t_node	*ptr;

	if (*b == NULL)
		return ;
	ptr = *b;
	*b = (*b)->next;
	ptr->next = *a;
	*a = ptr;
	return ;
}
//int			i;
// a to b 

void	checker_pb(t_node **a, t_node **b)
{
	t_node	*ptr;

	if (*a == NULL)
		return ;
	ptr = *a;
	*a = (*a)->next;
	ptr->next = *b;
	*b = ptr;
	return ;
}
